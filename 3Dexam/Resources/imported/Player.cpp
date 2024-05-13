#include "Player.h"
#include <iostream>




float Player::GetA()
{
    return a;
}


void Player::DeleteVBOANDVAO()
{
	VAO1.Delete();
	VBO1.Delete();

}

void Player::UnbindVAO()
{
	VAO1.Unbind();
}

void Player::BindVAO()
{
	VAO1.Bind();
}

void Player::UpdateVertices(float move_x, float move_y, float move_z)
{
	// Create a speed vector based on input
	glm::vec3 speed(move_x, move_y, move_z);

	// Normalize only if the speed vector is non-zero so diagonal movement is not faster 
	if (glm::length(speed) > 0.0f) {
		speed = glm::normalize(speed);
	}

	speed *= speedMagnifier;

	// Update position
	position += speed;


	//std::cout << glm::length(speed)<< std::endl;
}

VBO Player::GetVBO()
{
	return VBO1;
}

void Player::inputs(GLFWwindow* window)
{
	float move_x = 0.0f;
	float move_y = 0.0f;
	float move_z = 0.0f;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		move_z = -speedMagnifier;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		move_z = speedMagnifier;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		move_x = -speedMagnifier;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		move_x = speedMagnifier;
	}

	if ((glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) ||
		(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)) {
		move_x = 0.0f;
		move_y = 0.0f;
		move_z = 0.0f;
	}

	UpdateVertices(move_x, move_y, move_z);
}



bool Player::SphereCollision( Player& otherCube)
{
	float distance_centers = glm::length(position - otherCube.position);

	// If the distance between centers is less than the sum of the radius, collision occurs
	if (distance_centers <= (sphere_radius + otherCube.sphere_radius)) {

		float minimuntranslation = sphere_radius +otherCube.sphere_radius - distance_centers;
		auto dirvec = glm::normalize(position - otherCube.position);
		position += dirvec * minimuntranslation;
		//otherCube.position += dirvec * minimuntranslation;

		//otherCube.move = false;
		return true; 

	}
	else {

		//otherCube.move = true;
	}


	// No collision detected
	return false;
}


std::vector<double> computeDerivative(const std::vector<double>& coefficients) {
	std::vector<double> derivativeCoefficients;

	// Compute derivative coefficients
	for (size_t i = 1; i < coefficients.size(); ++i) {
		derivativeCoefficients.push_back(i * coefficients[i]);
	}

	return derivativeCoefficients;
}

double evaluatePolynomial(const std::vector<double>& coefficients, double x) {
	double result = 0.0;
	double power = 1.0;
	for (size_t i = 0; i < coefficients.size(); ++i) {
		result += coefficients[i] * power;
		power *= x;
	}
	return result;
}

double computeDerivativeAtPoint(const std::vector<double>& coefficients, double x) {
	std::vector<double> derivativeCoefficients = computeDerivative(coefficients);
	return evaluatePolynomial(derivativeCoefficients, x);
}


void Player::Patrol(std::vector<double> coefficients)
{
		double Derivative = computeDerivativeAtPoint(coefficients, xvalue) / 4096;
			position.x += xspeed / 2;
			if (xPositiveDir) position.z += Derivative;
			else position.z -= Derivative;

		xvalue += xspeed;
		if (xvalue >= 1) {
			xspeed *= -1;
			xPositiveDir = false;
		}
		else if (xvalue <= -0.25) {
			xspeed *= -1;
			xPositiveDir = true;
		}
}

void Player::Ai(glm::vec3 a, float maxX, float minX) {
	Math_class math; 

	// worked on in with Hans before exam
	//glm::vec3 x_cords = { 0, 1, 2 };
	//glm::vec3 y_cords = { 0, 5, -4 };

	//glm::vec3 coeffients = math.QuadraticInterpolation(x_cords, y_cords);
	glm::vec3 coeffients = a; 
	bool positiveDirection = true;

	// Update position based on the direction of motion
	float stepSize = 0.01f;
	position.x += stepSize * sign;
	if (position.x > maxX) {
		sign = -1;
	}
	if (position.x < minX) {
		sign = 1;
	}
	position.z = coeffients.x * powf(position.x, 2) + coeffients.y * powf(position.x, 1) + coeffients.z;
	//cout << "z Position " << position.z << endl;
}



glm::vec3 Player::calculateBarycentricCoordinates(glm::vec3& cpoint, bool ground)
{
	float u, v, w; 

	glm::vec3 point = cpoint;

	for (int i = 0; i < mVertecies.size() - 2; i += 3)
	{


		glm::vec3 v0 = glm::vec3((mVertecies[i].x * size1) + position.x, (mVertecies[i].y * size1) + position.y, (mVertecies[i].z * size1) + position.z);
		glm::vec3 v1 = glm::vec3((mVertecies[i + 1].x * size1) + position.x, (mVertecies[i + 1].y * size1) + position.y, (mVertecies[i + 1].z * size1) + position.z);
		glm::vec3 v2 = glm::vec3((mVertecies[i + 2].x * size1) + position.x, (mVertecies[i + 2].y * size1) + position.y, (mVertecies[i + 2].z * size1) + position.z);


		if (!ground)
		{
			v0.y = 0;
			v1.y = 0;
			v2.y = 0;
			point.y = 0;
		}


		glm::vec3 v0v1 = v1 - v0; 
		glm::vec3 v0v2 = v2 - v0; 
		glm::vec3 v0p = point - v0; 

		// Compute dot products
		float dot00 = glm::dot(v0v1, v0v1); // v0v1^2
		float dot01 = glm::dot(v0v1, v0v2);
		float dot02 = glm::dot(v0v1, v0p);
		float dot11 = glm::dot(v0v2, v0v2); // v0v2^2
		float dot12 = glm::dot(v0v2, v0p);

		// Compute barycentric coordinates
		float invDenom = 1 / (dot00 * dot11 - dot01 * dot01); // arealet av trekanten / 1 for å gange senere 
		 v = (dot11 * dot02 - dot01 * dot12) * invDenom;
		 w = (dot00 * dot12 - dot01 * dot02) * invDenom;
		 u = 1 - w - v;
		if (u > 0 && v > 0 && w > 0) {
			if (ground)
			{
				float height = v0.y * u + v1.y * v + v2.y * w; // Pu * Qv * Rw = point
				cpoint.y = height + 1.f; 
			}
			
			else
			{
				cpoint.y += 1;
			}
		}

		//else {
		//    std::cout << "x: " << u << std::endl;
		//    std::cout << "y: " << v << std::endl;
		//    std::cout << "z: " << w << std::endl;
		//}
	}

	return glm::vec3(u, v, w);
}

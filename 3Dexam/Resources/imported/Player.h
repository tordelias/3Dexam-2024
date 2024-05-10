#pragma once
#include "../Shaders/VAO.h"
#include "../Shaders/VBO.h"
#include <vector>
#include <array>
#include <string>
#include <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<GLFW/glfw3.h>
#include <cmath>
#include "Construct.h"

//Code is from: tordelias/Compulsory-3/OpenGlsession0/player.h
//Github Link: https://github.com/tordelias/Compulsory-3.git

using namespace std;

class Player {
private:

	float sphere_radius = 0;
	bool move = true;
	float size1 = 1.f;
	float r, g, b;
	VAO VAO1;
	VBO VBO1;
	glm::vec3 velocity;

public:
	std::vector<Vertex> mVertecies;
	glm::vec3 position;

	Player(float scale, const glm::vec3& initialPosition, float red = 1.0f, float green = 1.0f, float blue = 1.0f, float figure = 1.f)
		: a(scale), position(initialPosition), velocity(glm::vec3(0.0f)), r(red), g(green), b(blue), VBO1()
	{
		Construct con;

		//Cube
		if (figure == 1)
		{
			mVertecies = con.Cube(glm::vec3(red, green, blue));

		}
		else if (figure == 2)
		{
			mVertecies = con.Table(glm::vec3(red, green, blue));
		}

		else if (figure == 3)
		{
			mVertecies = con.House(glm::vec3(red, green, blue));
		}

		else if (figure == 4)
		{
			mVertecies = con.NotAPlane(glm::vec3(red, green, blue));
		}
		else if (figure == 5)
		{
			mVertecies = con.Triangle(glm::vec3(red, green, blue));
		}
		else if (figure == 6)
		{
			mVertecies = con.Square(glm::vec3(red, green, blue));
		}
		else if (figure == 7)
		{
			mVertecies = con.Line(glm::vec3(red, green, blue));
		}
		else
		{
			mVertecies = con.CubeNoTexture(glm::vec3(red, green, blue));
		}
		VAO1.Bind();
		VBO1.Bind();
		glBufferData(GL_ARRAY_BUFFER, mVertecies.size() * sizeof(Vertex), mVertecies.data(), GL_STATIC_DRAW);
		VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		VAO1.Unbind();
		VBO1.Unbind();
		
		size1 = scale; 
		sphere_radius = a; 

	}
	float GetA();
	/*std::vector<GLfloat> getFlattenedVertices() const;*/
	/*void ConstructVBO(std::vector<GLfloat> flattenedVertices, bool update);*/
	void DeleteVBOANDVAO();
	void UnbindVAO();
	void BindVAO();
	void UpdateVertices(float Xspeed, float Yspeed, float Zspeed, glm::vec3 velocity);
	VBO GetVBO();
	void inputs(GLFWwindow* window);

	void Patrol(std::vector<double> coefficients);
	
	bool CheckCollision( Player& otherCube);
	


	glm::vec3 calculateBarycentricCoordinates( glm::vec3& cpoint, bool ground);

public:
	float a{ 1.0f };
	double xvalue = 0;
	double xspeed = 0.001;
	bool xPositiveDir = true;


};
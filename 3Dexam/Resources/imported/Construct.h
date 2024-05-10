#define GLM_ENABLE_EXPERIMENTAL
#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
//Code is from: tordelias/Compulsory-3/OpenGlsession0/Construct.h
//Github Link: https://github.com/tordelias/Compulsory-3.git
struct Vertex
{
	float x, y, z;
	float r, g, b;
	float u, v; 

};
class Construct
{
public:
	std::vector<Vertex> Cube(glm::vec3 Color);
	std::vector<Vertex> CubeNoTexture(glm::vec3 Color);
	std::vector<Vertex> Table(glm::vec3 Color);
	std::vector<Vertex> House( glm::vec3 Color);
	std::vector<Vertex> NotAPlane(glm::vec3 Color);
	std::vector<Vertex> Triangle(glm::vec3 Color);
	std::vector<Vertex> Square(glm::vec3 Color);
	std::vector<Vertex> Line(glm::vec3 Color);


	float randomFloat() {
		return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	}
};


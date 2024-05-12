#pragma once
#include "glm/glm.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
class Math_class
{
	//Some of the code is from: tordelias/Compulsory-1_Math-Prog/MyOpenGL1/Main.cpp
	//Github Link: https://github.com/tordelias/Compulsory-1_Math-Prog.git
public:
	glm::vec<4,double> CubicInterpolation(glm::vec4 x_Cords, glm::vec4 y_Cords);
	glm::vec<3, double> QuadraticInterpolation(glm::vec3 x_Cords, glm::vec3 y_Cords);
	void WriteToFile(const char *name, float x, float y, float z);
	void ReadFile(const char* name, std::vector<float> &cords);
};


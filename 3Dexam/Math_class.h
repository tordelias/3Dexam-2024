#pragma once
#include "glm/glm.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
class Math_class
{
public:
	glm::vec<4,double> CubicInterpolation(glm::vec4 x_Cords, glm::vec4 y_Cords);
	void WriteToFile(const char *name, float x, float y, float z);
	void ReadFile(const char* name, std::vector<float> &cords);
};


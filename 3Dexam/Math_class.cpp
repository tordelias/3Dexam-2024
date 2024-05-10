#include "Math_class.h"

glm::vec<4, double> Math_class::CubicInterpolation(glm::vec4 x_Cords, glm::vec4 y_Cords)
{
    glm::mat<4,4,double> A(
        powf(x_Cords.x, 3), powf(x_Cords.y, 3), powf(x_Cords.z, 3), powf(x_Cords.w, 3),
        powf(x_Cords.x, 2), powf(x_Cords.y, 2), powf(x_Cords.z, 2), powf(x_Cords.w, 2),
        powf(x_Cords.x, 1), powf(x_Cords.y, 1), powf(x_Cords.z, 1), powf(x_Cords.w, 1),
        powf(x_Cords.x, 0), powf(x_Cords.y, 0), powf(x_Cords.z, 0), powf(x_Cords.w, 0)
    );
    return (glm::inverse(A) * y_Cords);
}

void Math_class::WriteToFile(const char *name, float x, float y, float z)
{

        const char* fileName = name;
        std::ofstream Outputfile(fileName, std::ios::app);
        if (Outputfile.is_open())
        {
            Outputfile << std::fixed << std::setprecision(3);
            Outputfile << x << ", " << y << ", " << z << ", " << std::endl;
        }
        //else
        //{
        //    std::cout << "Unable to open file" << std::endl;
        //}
        Outputfile.close();
    
}

void Math_class::ReadFile(const char* name, std::vector<float> &cords)
{
    std::ifstream file(name);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << name << std::endl;
        return;
    }

    //std::string line;
    // Skip the first line (header)
    //std::getline(file, line);

    size_t i = 0;
    float x, y, z;
    char comma;

    if (file.is_open())
    {
        while (file >> x >> comma >> y >> comma >> z)
        {
            cords.push_back(x);
            cords.push_back(y);
            cords.push_back(z);
        }
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
    file.close();
}

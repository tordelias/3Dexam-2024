#ifndef LSM_H
#define LSM_H

#include <vector>
#include <string>

//Code is from:Compulsory-2-3DProg/OpenGLSession0/LSM.h
// Github Link: https://github.com/HansPluss/Compulsory-2-3DProg.git 

class LSM {
private:
    std::vector<double> coefficients;

public:
    // Constructor
    LSM(const std::vector<double>& xy, int degree);

    // Function to calculate coefficients of the polynomial using the least squares method
    std::vector<double> leastSquaresMethod(const std::vector<double>& xy, int degree);

    // Function to generate a string representation of the polynomial equation
    std::string polynomialString();

    // Function to print coefficients
    void printCoefficients();

    std::vector<double> getCoefficients();
};

#endif

#include <iostream>


class Triangle{ private:
double totalAngle, angleA, angleB, angleC;//The code declares the variables as private variables, using double for a more precise computation.
public:
Triangle(double A, double B, double C);// Public variables to be used by other functions
void setAngles(double A, double B, double C); const bool validateTriangle();
};
Triangle::Triangle(double A, double B, double C) { angleA = A;
angleB = B; angleC = C;
totalAngle = A+B+C;
}
void Triangle::setAngles(double A, double B, double C) { angleA = A;
angleB = B; angleC = C;
totalAngle = A+B+C;//The function computes for the total angle of the given values.
}

const bool Triangle::validateTriangle() { return (totalAngle <= 180);
}//The code checks if the total angle is less than or equal to 180, if it is, it returns 1, otherwise, it will return 0.

int main() {
//driver code
Triangle set1(40, 30, 110); if(set1.validateTriangle()){// Uses the previously defined functions to determine if the shape is a valid or not valid function.
std::cout << "The shape is a valid triangle.\n";//Output when the total angle is less than or equal to 180.
} else {
std::cout << "The shape is NOT a valid triangle.\n";//Output when the total angle is greater than 180.
}

return 0;

}
#include <iostream>
float conversion(float a);
int main() {
    float a=0;
std::cout<<"Enter temperature in Kelvin: ";
std::cin>>a;
std::cout<<a<<" Kelvin to Fahrenheit is: "<<conversion(a);

    return 0;
}
float conversion(float a)
{
    return 1.8*(a-273.15)+32;
}
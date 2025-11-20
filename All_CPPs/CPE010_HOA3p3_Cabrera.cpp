#include <iostream>

void switch1(int a, int b);
int main() {
    int a=0;
    int b=0;
std::cout<<"Please enter value for A: ";
std::cin>>a;
std::cout<<"Please enter value for B: ";
std::cin>>b;
 switch1(a,b);

    return 0;
}
void switch1 (int a, int b)
{
    std::cout<<"Initial A value: "<<a<<std::endl;
    std::cout<<"Initial B value: "<<b<<std::endl;
    int c=a;
    a=b;
    b=c;
    std::cout<<"Value A is now:"<<a<<std::endl;
    std::cout<<"Value B is now:"<<b<<std::endl;
}
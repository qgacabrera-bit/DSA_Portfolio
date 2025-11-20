#include <iostream>


void add(int a, int b);
void compare(int c, int d);
bool logic(bool a, bool b);
int main() {
    add(5,6);
    compare(3,7);
    logic(1,0);
    
    return 0;
}
void add(int a, int b)
{
    std::cout<<a<<" + "<<b<<" = "<<a+b<<std::endl;
}

void compare(int c, int d)
{
   if (c>d)
    {
        std::cout<<c<<" is greater than "<<d<<std::endl;
    }
    else if (c<d)
    {
        std::cout<<c<<" is less than "<<d<<std::endl;
    }
    else
    {
        std::cout<<"Both numbers are equal."<<std::endl;
    }
}
bool logic(bool a, bool b)
{
    bool OrFunc=a||b;
    bool NotOrFunc=!(OrFunc);
    bool AndFunc=a&&b;
    bool NotAndFunc=!(AndFunc);
    std::cout<<"OR result: "<<OrFunc<<std::endl;
    std::cout<<"AND result: "<<AndFunc<<std::endl;
    std::cout<<"NOT OR result: "<<NotOrFunc<<std::endl;
    std::cout<<"NOT AND result: "<<NotAndFunc<<std::endl;
    return true;
}
    
}
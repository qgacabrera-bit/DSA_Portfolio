#include <iostream>
#include <thread>


int num = 100;


void FunctionCall(int n){

    for(int i = 0; i <= n; i++){
        num+=i;
    }
    std::cout << num << " - Sum from FunctionCall\n";
}

class ObjectCall{
public:
    void operator()(int n){
        for(int i = 0; i <= n; i++){
            num+=i;
        }
        std::cout << num << " - Sum from ObjectCall\n";
    }
};

int main() {
    auto f = [](int n){
        for(int i = 0; i <= n; i++){
            num+=i;
        }
        std::cout << num << " - Sum from Lambda Expression\n";
    };
    std::thread th1(FunctionCall, 10);
    std::thread th2(ObjectCall(), 10);
    std::thread th3(f, 10);

    th1.join();
    th2.join();
    th3.join();
    return 0;
}

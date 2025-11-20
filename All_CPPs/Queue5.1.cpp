#include <iostream>
#include <string>
#include <queue>
template <typename T>
void displayAll(std::queue<T> n);

int main() {
std::string list1[5] = {"Gabriel", "Base", "Lynn", "Tamayo", "Ycay"};
std::queue<std::string> queue1;

for(int i = 0; i < 5; i++){
queue1.push(list1[i]);
}

displayAll(queue1);

}

template <typename T>
void displayAll(std::queue<T> n){
while(!n.empty()){
std::cout << n.front() << std::endl;
n.pop();
}
}



#include "queueArr.h"
#include <string>

template <typename T>
void displayAll(queueArr<T> queue1);

int main(){
    
    std::string studentArr[5] = {"A", "B", "C", "D", "E"};
    queueArr<std::string> studentQueue(5);

    
    int i = 0;
    while(!studentQueue.isFull()){
        studentQueue.enqueue(studentArr[i]);
        i++;
    }

    studentQueue.Front();
    studentQueue.Back();

    displayAll(studentQueue);

    return 0;
}

template <typename T>
void displayAll(queueArr<T> queue1){
    while(!queue1.isEmpty()){
        queue1.Front();
        queue1.dequeue();
    }
}
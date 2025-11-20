
#ifndef QUEUE_ARR_H
#define QUEUE_ARR_H
#include<iostream>

template <typename T>
class queueArr{
    //data members
    T *q_array;
    int q_capacity;
    int q_size = 0, q_front = 0, q_back = 0;
public:
    queueArr(int newCap){
        q_capacity = newCap;
        q_array = new T[q_capacity];
    }

    bool isEmpty(){
        return q_size==0;
    }

    bool isFull(){
        return q_size==q_capacity;
    }

    int qSize(){
        return q_size;
    }

    void clear(){
        q_size = 0; q_front = 0; q_back = 0;
    }

    void Front(){
        //check if empty
        if(isEmpty()){
            std::cout << "Queue is Empty.\n";
            return;
        }
        std::cout << "Front: " << q_array[q_front%q_capacity] << std::endl;
    }

    void Back(){
        //check if empty
        if(isEmpty()){
            std::cout << "Queue is Empty.\n";
            return;
        }
        std::cout << "Back: " << q_array[q_back%q_capacity] << std::endl;
    }

    void enqueue(T newData);
    void dequeue();

    //the big three

    //Copy Constructor
    queueArr(const queueArr& obj){
        std::cout << "\nCopy Constructor is called" << std::endl;
        q_capacity = obj.q_capacity;
        q_size = obj.q_size;
        q_array = obj.q_array;
        q_front = obj.q_front;
        q_back = obj.q_back;
    }

    //Copy Assignment Operator
    queueArr& operator=(const queueArr& obj){
        std::cout << "\nAssignment Operator is Called" << std::endl;
        q_capacity = obj.q_capacity;
        q_size = obj.q_size;
        q_array = obj.q_array;
        q_front = obj.q_front;
        q_back = obj.q_back;
        return *this;
    }

    //Destructor
    ~queueArr(){
        std::cout << "\nDestructor is called." << std::endl;
        Front();
        Back();
    }
};

template<typename T>
void queueArr<T>::enqueue(T newData){
    //check if full
    if(isFull()){
        std::cout << "Cannot add: Queue is Full.\n";
        return;
    }
    //check if it's empty
    if(isEmpty()){
        q_array[q_front%q_capacity] = newData;
        //Front();
        //Back();
        //if front == back in display, correct operation!
        q_size++;
        return;
    }
    //normal enqueue
    q_back++;
    q_array[q_back%q_capacity] = newData;
    //Front();
    //Back();
    q_size++;
}

template<typename T>
void queueArr<T>::dequeue() {
    //check if it's empty
    if(isEmpty()){
        std::cout << "Cannot dequeue: Queue is empty.\n";
        return;
    }
    //check if there's only 1 element
    if(q_size==1){
        std::cout << q_array[q_front%q_capacity] << " was successfully dequeued.\n";
        clear();
        //Front();
        return;
    }
    //normal dequeue
    std::cout << q_array[q_front%q_capacity] << " was successfully dequeued.\n";
    q_front++;
    q_size--;
}
#endif 

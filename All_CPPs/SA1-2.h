#ifndef HOA_SEARCHING_TECHNIQUES_SA1_2_H
#define HOA_SEARCHING_TECHNIQUES_SA1_2_H
#include <iostream>

template <typename T>
class Node{
public:
    T data;
    Node *next;
};

template <typename T>
Node<T> *createNode(T newData){
    Node<T> *newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

template <typename T>
void P1arrSearch(int arrSize, T data[], T item){
    int i = 0;
    while(i <= arrSize){
        if(item == data[i]){
            std::cout << data[i] << " was found. Using Array" << std::endl;
            std::cout << "Comparisons: " << i+1  << std::endl;
            return;
        }
        i++;
    }
    std::cout << "Searching is unsuccessful.\n";
}

template <typename T>
void P1linkedSearch(T item, Node<T> *head){
    Node<T> *currentNode = head;
    while(currentNode != nullptr){
        if(item == currentNode->data){
            std::cout << item << " was found. Using Linked List" << std::endl;
            return;
        }
        currentNode = currentNode->next;
    }
    std::cout << "Searching is unsuccessful.\n";
}

template <typename T>
int P2countNum(T arrSize, T data[], T item){
    int n = 0;
    for(int i = 0; i < arrSize; i++){
        if(data[i] == item){
            n++;
        }
    }
    return n;
}
#endif

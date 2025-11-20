#ifndef TABLE_6_2B_LINEAR_SEARCH_FOR_LINKED_LIST_H
#define TABLE_6_2B_LINEAR_SEARCH_FOR_LINKED_LIST_H
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
void linearLinkedSearch(T item, Node<T> *head){
    Node<T> *currentNode = head;
    while(currentNode != nullptr){
        if(item == currentNode->data){
            std::cout << item << " was found. Searching is successful.\n";
            return;
        }
        currentNode = currentNode->next;
    }
    std::cout << "Searching is unsuccessful.\n";
}

#endif

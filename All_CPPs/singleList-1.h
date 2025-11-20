//
// Created by gabca on 8/14/2025.
//

#ifndef UNTITLED1_SINGLELIST_H
#define UNTITLED1_SINGLELIST_H

#include <iostream>

template <typename T> //make it accept any data type
class singleList {
public:
    T data; //data
    singleList *next = nullptr; //pointer to the next
};

//traverse the given list
template <typename T>
void sllTraverse(singleList<T> *n){
    while(n!=NULL){
        std::cout << n->data;
        if(n->next!=NULL){
            std::cout << "->";
        } else {
            std::cout << std::endl;
        }
        n = n->next;
    }
    std::cout << std::endl;
}

//insertion at the head
template <typename T>
void sllinsertHead(T newData, singleList<T> **currentHead){
    singleList<T> *newNode = new singleList<T>;
    newNode->data = newData;
    newNode->next = *currentHead;
    (*currentHead) = newNode;
}

//insertion after a node
template <typename T>
void sllGeneralInsert(T newData, singleList<T> *prevNode){
    if(prevNode== NULL){
        throw std::invalid_argument("Previous node cannot be null.");
        return;
    }

    singleList<T> *newNode = new singleList<T>;
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

//insertion at the end
template <typename T>
void sllInsertEnd(T newData, singleList<T> **head){
    singleList<T> *newNode = new singleList<T>;
    singleList<T> *currentNode = *head;
    newNode->data = newData;
    newNode->next = NULL;

    while(currentNode->next!=NULL){
        std::cout << currentNode->data;
        if(currentNode->next!=NULL){
            std::cout << "->";
        }
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    std::cout << currentNode->data;
    std::cout << std::endl;
}

//deletion of the node
template <typename T>
void sllDelete(singleList<T> **head, T findData){
    singleList<T> *currNode = *head;
    singleList<T> *prevNode = nullptr;

    while(currNode->next->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }

    prevNode->next = currNode->next;
    delete currNode;

}

#endif //UNTITLED1_SINGLELIST_H
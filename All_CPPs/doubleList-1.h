//
// Created by gabca on 8/14/2025.
//

#ifndef UNTITLED1_DOUBLELIST_H
#define UNTITLED1_DOUBLELIST_H
#include <iostream>

template <typename T>
class doubleList {
public:
    T data;
    doubleList *prev = nullptr;
    doubleList *next = nullptr;
};

//newNode
template <typename T>
doubleList<T> *new_node(T newData){
    doubleList<T> *newNode = new doubleList<T>;
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

//traverse the given list
template <typename T>
void dllTraverse(doubleList<T> *currentNode) {
    doubleList<T> *last;
    std::cout << "Forward:\t";
    while(currentNode!=NULL){
        std::cout << currentNode->data << " ";
        last = currentNode;
        currentNode = currentNode->next;
    }
    std::cout << std::endl << "Backward:\t";
    while(last!=NULL){
        std::cout << last->data << " ";
        last = last->prev;
    }
    std::cout << std::endl;
}

//insertion at the head
template <typename T>
void dllinsertHead(T newData, doubleList<T> **currentHead){
    doubleList<T> *newNode = new doubleList<T>;
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = *currentHead;
    (*currentHead)->prev = newNode;

    (*currentHead) = newNode;
}

//insert at the end
template <typename T>
void dllinsertEnd(T newData, doubleList<T> *currentHead){
    doubleList<T> *newNode = new doubleList<T>;
    newNode->data = newData;

    while(currentHead->next!=NULL){
        currentHead = currentHead->next;
    }

    newNode->next = NULL;
    currentHead->next = newNode;
    newNode->prev = currentHead;
}

//insert after a node
template <typename T>
void dllinsertAny(T newData, doubleList<T> *prevNode){
    if(prevNode==NULL){
        throw std::invalid_argument("Previous node cannot be null.");
    }

    doubleList<T> *newNode = new doubleList<T>;
    newNode->data = newData;

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    prevNode->next->prev = newNode;
    prevNode->next = newNode;
}

template <typename T>
void dllDelete(T key, doubleList<T> **head){
    doubleList<T> *temp = *head, *prev;

    //check if head node
    if(key==(*head)->data){
        (*head)->next->prev = NULL;
        temp = *head;
        (*head) = temp->next;

        delete temp;
        temp = NULL;
        return;
    }

    while(temp->data!=key){
        prev = temp;
        temp = temp->next;
    }

    if(temp->next==NULL){
        prev->next = NULL;
        delete temp;
        temp = NULL;
        return;
    }

    prev->next = temp->next;
    temp->next->prev = prev;

    delete temp;
    temp = NULL;
}


#endif //UNTITLED1_DOUBLELIST_H
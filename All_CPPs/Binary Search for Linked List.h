#ifndef MAIN_CPP_BINARY_SEARCH_FOR_LINKED_LIST_H
#define MAIN_CPP_BINARY_SEARCH_FOR_LINKED_LIST_H
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
    newNode->next = NULL;
    return newNode;
}

template <typename T>
Node<T> *getMiddle(Node<T> *first, Node<T> *last){
    Node<T> *fast = first, *slow = first;
    while(fast != last){
        slow = slow->next;
        fast = fast->next;
        if(fast->next != nullptr){
            fast = fast->next;
        }
    }
    return slow;
}

template <typename T>
void binaryLinkedSearch(T dataFind, Node<T> *head, Node<T> *tail){
    Node<T> *low = head, *up = tail, *middle;
    while(low != up){
        middle = getMiddle(low, up);
        if(dataFind == middle->data){
            std::cout << "Search element is found!\n";
            return;
        } else if (dataFind < middle->data){
            up = middle;
        } else {
            low = middle->next;
        }
    }
    std::cout << "Search element is not found.\n";
}
#endif

#include<iostream>
#include<utility>
#include "singleList.h"
#include "doubleList.h"

class Node{
public:
    char data;
    Node *next;
};

int main(){
    singleList<char> *head   = new singleList<char>();
    singleList<char> *second = new singleList<char>();
    singleList<char> *third  = new singleList<char>();
    singleList<char> *fourth = new singleList<char>();
    singleList<char> *fifth  = new singleList<char>();
    singleList<char> *last   = new singleList<char>();
    //step 3
    head->data = 'C';
    head->next = second;
    second->data = 'P';
    second->next = third;
    third->data = 'E';
    third->next = fourth;
    fourth->data = '0';
    fourth->next = fifth;
    fifth->data = '1';
    fifth->next = last;
    //step 4
    last->data = '0';
    last->next = nullptr;

    sllinsertHead('G', &head);

    singleList<char> *temp = head;
    while (temp != nullptr && temp->data != 'P') {
        temp = temp->next;
    }
    if (temp != nullptr) {
        sllGeneralInsert('E', temp);
    }


    sllTraverse(head);

    return 0;
}

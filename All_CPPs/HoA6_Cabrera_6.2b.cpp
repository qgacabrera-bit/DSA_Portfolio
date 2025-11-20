#include "Linear Search for Linked List.h"

int main(){
    Node<char> *newnode1 = createNode('G');
    Node<char> *newnode2 = createNode('A');
    Node<char> *newnode3 = createNode('B');
    Node<char> *newnode4 = createNode('R');
    Node<char> *newnode5 = createNode('I');
    Node<char> *newnode6 = createNode('E');
    Node<char> *newnode7 = createNode('L');

    newnode1->next = newnode2;
    newnode2->next = newnode3;
    newnode3->next = newnode4;
    newnode4->next = newnode5;
    newnode5->next = newnode6;
    newnode6->next = newnode7;

    linearLinkedSearch('A', newnode1);
    return 0;
}

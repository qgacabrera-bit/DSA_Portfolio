#include "SA1-2.h"

const int max_size = 10;

int main() {
    int dataset[max_size] = {5, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    for(int i = 0; i < 10; i++){
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    Node<int> *newnode1 = createNode(5);
    Node<int> *newnode2 = createNode(18); newnode1->next = newnode2;
    Node<int> *newnode3 = createNode(2); newnode2->next = newnode3;
    Node<int> *newnode4 = createNode(19); newnode3->next = newnode4;
    Node<int> *newnode5 = createNode(18); newnode4->next = newnode5;
    Node<int> *newnode6 = createNode(0); newnode4->next = newnode6;
    Node<int> *newnode7 = createNode(8); newnode4->next = newnode7;
    Node<int> *newnode8 = createNode(14); newnode4->next = newnode8;
    Node<int> *newnode9 = createNode(19); newnode4->next = newnode9;
    Node<int> *newnode10 = createNode(14); newnode4->next = newnode10;

    P1arrSearch(max_size, dataset, 18);
    P1linkedSearch(18, newnode1);

    int dataFind = 18;
    std::cout<< "Count of repeating number (k): " << P2countNum(max_size, dataset, dataFind);

    return 0;
}

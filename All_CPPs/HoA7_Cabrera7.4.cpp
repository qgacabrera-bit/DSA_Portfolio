#include <iostream>
#include <cstdlib>
#include <time.h>
#include "insertionSort.h"

const int max_size = 100;

void randomArr(int arr[]);
void displayArr(int arr[]);

int main() {
    int unsortedList[max_size];
    srand(time(0));
    for(int i = 0; i < max_size; i++){
        unsortedList[i] = rand() % 100;
        std::cout << unsortedList[i] << " ";
    }

    randomArr(unsortedList);
    std::cout << "\nINSERTION SORT\n" << std::endl;
    insertionSort(unsortedList, max_size);
    displayArr(unsortedList);

    return 0;
}

void randomArr(int arr[]){
    int unsortedList[max_size];
    srand(time(0));
    for(int i = 0; i < max_size; i++){
        unsortedList[i] = rand() % 100;
    }
}

void displayArr(int arr[]){
    for(int i = 0; i < max_size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

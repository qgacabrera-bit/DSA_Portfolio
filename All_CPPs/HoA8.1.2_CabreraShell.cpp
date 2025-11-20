#include <iostream>
#include <cstdlib>
#include <time.h>
#include "shellSort.h"

const int max_size = 100;

void randomArr(int arr[]);
void displayArr(int arr[]);

int main() {
    int unsortedList[max_size];

    randomArr(unsortedList);
    std::cout << "SHELL SORT" << std::endl;
    shellSort(unsortedList, max_size);
    displayArr(unsortedList);
    return 0;
}

void randomArr(int arr[]){
    srand(time(0));
    for(int i = 0; i < max_size; i++){
        arr[i] = rand() % 100;
    }
}

void displayArr(int arr[]){
    for(int i = 0; i < max_size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


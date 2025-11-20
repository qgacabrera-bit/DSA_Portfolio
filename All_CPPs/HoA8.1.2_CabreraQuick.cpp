#include <iostream>
#include <cstdlib>
#include <time.h>
#include "quickSort.h"

const int max_size = 100;

void randomArr(int arr[]);
void displayArr(int arr[]);

int main() {
    int unsortedList[max_size];

    randomArr(unsortedList);
    std::cout << "QUICK SORT" << std::endl;
    quickSort(unsortedList, 0, max_size-1);
    displayArr(unsortedList);

    std::cout << std::endl;
    int sampleList[15] = {4,34,29,48,53,87,12,30,44,25,93,67,43,19,74};
    for(int i = 0; i < 15; i++){
        std::cout << sampleList[i] << " ";
    }

    quickSort(sampleList, 0, 15-1);
    displayArr(sampleList);

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


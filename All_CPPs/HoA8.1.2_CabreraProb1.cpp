#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Problem1.h"

const int max_size = 100;

void randomArr(int *arr);
void displayArr(int *arr);

int main(){
    int unsortedList[max_size];
    randomArr(unsortedList);
    displayArr(unsortedList);

    std::cout << std::endl;
    std::cout << "SORTED LIST" << std::endl;
    quickSort(unsortedList, 0, max_size-1);
    displayArr(unsortedList);

    return 0;
}

void randomArr(int *arr){
    srand(time(0));
    for(int i = 0; i < max_size; i++){
        arr[i] = rand() % 10;
    }
}

void displayArr(int *arr){
    for(int i = 0; i < max_size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


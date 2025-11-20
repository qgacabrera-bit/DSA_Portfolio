#include "Binary Search for Arrays.h"
#include <cstdlib>
#include <time.h>

const int max_size = 999;

int main(){
    int dataset[max_size];
    srand(time(0));
    for(int i = 0; i < max_size; i++){
        dataset[i] = rand() % 100;
    }

    int sortedList[max_size];
    for(int i = 0; i < max_size; i++){
        sortedList[i] = i+1;
    }

    binarySearch(max_size, sortedList, 420);

    return 0;
}


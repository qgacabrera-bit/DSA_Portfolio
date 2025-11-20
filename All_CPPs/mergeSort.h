#ifndef TABLE_8_3_MERGESORT_H
#define TABLE_8_3_MERGESORT_H
#include <iostream>

void merge(int *subArr, int first, int mid, int last);

void mergeSort(int *arr, int first, int last){
    if(first == last) return;

    if(first < last){
        int middle = (first+last)/2;
        mergeSort(arr, first, middle);
        mergeSort(arr, middle+1, last);
        merge(arr, first, middle, last);
    }
}

void merge(int *subArr, int first, int mid, int last){
    int temp[last+1], indexLeft = first, indexRight = mid+1;
    int i;

    for(i = first; indexLeft <= mid && indexRight <= last; i++){
        if(subArr[indexLeft] < subArr[indexRight]){
            temp[i] = subArr[indexLeft];
            indexLeft++;
        } else {
            temp[i] = subArr[indexRight];
            indexRight++;
        }
    }

    while(indexLeft <= mid){
        temp[i] = subArr[indexLeft];
        i++; indexLeft++;
    }

    while(indexRight <= last){
        temp[i] = subArr[indexRight];
        i++; indexRight++;
    }

    //std::cout << std::endl;
    for(int j = first; j < i; j++){
        //std::cout << temp[j] << " ";
        subArr[j] = temp[j];
    }

    //std::cout << std::endl;
}
#endif //TABLE_8_3_MERGESORT_H

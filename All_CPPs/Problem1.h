#ifndef PROBLEM_1_PROBLEM1_H
#define PROBLEM_1_PROBLEM1_H
#include <iostream>
void merge(int *subArr, int first, int mid, int last);
int partition(int *arr, int low, int high);

void mergeSort(int *arr, int first, int last){
    if(first==last) return;

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

    for(i = first; indexLeft <= mid && indexRight <= last; i++) {
        if (subArr[indexLeft] < subArr[indexRight]) {
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

void quickSort(int *arr, int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        mergeSort(arr, low, pivot-1);
        mergeSort(arr, pivot+1, high);
    }
}

int partition(int *arr, int low, int high){
    int middle = (low+high)/2;

    int temp = arr[middle];
    arr[middle] = arr[high];
    arr[high] = temp;

    int left = low, right = high-1;

    while(arr[left] < arr[high]){
        left++;
    }

    while(right > left){
        if(arr[right] < arr[high]) {
            temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
            while(arr[left] < arr[high]){
                left++;
            }
        }
        right--;
    }

    temp = arr[left];
    arr[left] = arr[high];
    arr[high] = temp;

    return left;
}
#endif //PROBLEM_1_PROBLEM1_H

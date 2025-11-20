#include <iostream>
#include <time.h>
#include <thread>
#include <vector>

const int max_size = 100;

void randomArr(int *arr);
void displayArr(int *arr);

//Quick Sort Algorithm
int partition(int *arr, int low, int high);
void quickSort(int *arr, int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
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
        if(arr[right] < arr[left]){
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

//Merge Sort Algorithm
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

    for(int j = first; j < i; j++){
        subArr[j] = temp[j];
    }
}

int main() {
    int unsortedList[max_size];
    randomArr(unsortedList);
    std::cout << "Unsorted List" << std::endl;
    displayArr(unsortedList);
    std::cout << "Sorting using QuickSort" << std::endl;
    std::thread th1(quickSort, unsortedList, 0, max_size-1);
    th1.join();
    displayArr(unsortedList);

    std::cout << std::endl;

    randomArr(unsortedList);
    std::cout << "Unsorted List" << std::endl;
    displayArr(unsortedList);
    std::cout << "Sorting using MergeSort" << std::endl;
    std::thread th2(mergeSort, unsortedList, 0, max_size-1);
    th2.join();
    displayArr(unsortedList);
    return 0;
}

void randomArr(int *arr){
    srand(time(0));
    for(int i = 0; i < max_size; i++){
        arr[i] = rand() % 100;
    }
}

void displayArr(int *arr){
    for(int i = 0; i < max_size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
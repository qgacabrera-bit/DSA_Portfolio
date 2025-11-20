#ifndef TABLE_6_3A_BINARY_SEARCH_FOR_ARRAYS_H
#define TABLE_6_3A_BINARY_SEARCH_FOR_ARRAYS_H
#include <iostream>

template <typename T>
void binarySearch(int arrSize, T data[], T item){
    int low = 0, up = arrSize-1, mid;
    while(low <= up){
        mid = (low+up)/2;
        if(item == data[mid]){
            std::cout << "Search element is found.\n";
            return;
        } else if (item < data[mid]){
            up = mid-1;
        } else {
            low = mid+1;
        }
    }
    std::cout << "Search element is not found.\n";
}
#endif 

#ifndef TABLE_6_2A_LINEAR_SEARCH_FOR_ARRAYS_H
#define TABLE_6_2A_LINEAR_SEARCH_FOR_ARRAYS_H
#include <iostream>

template <typename T>
void linearSearch(int arrSize, T data[], T item){
    int i = 0;
    while(i <= arrSize){
        if(item == data[i]){
            std::cout << data[i] << " was found. Searching is successful.\n";
            return;
        }
        i++;
    }
    std::cout << "Searching is unsuccessful.\n";
}

#endif

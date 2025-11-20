#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
template <typename T>
void insertionSort(T arr[], const int arrSize){
    int K = 1, J;
    T temp;
    while(K < arrSize){
        temp = arr[K];
        J = K-1;
        while(temp <= arr[J]){
            arr[J+1] = arr[J];
            J--;
            if(J < 0) break;
        }
        arr[J+1] = temp;
        K++;
    }
}
#endif

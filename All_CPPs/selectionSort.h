#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
template <typename T> int routineSmallest(T subArr[], int K, const int arrSize);

template <typename T>
void selectionSort(T arr[], const int arrSize){
    int POS, pass = 0;
    T temp;
    for(int i = 0; i < arrSize; i++){
        POS = routineSmallest(arr, i, arrSize);
        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;

        pass++;
    }
}

template <typename T>
int routineSmallest(T subArr[], int K, const int arrSize){
    int position = K; T smallestElement = subArr[K];
    for(int J = K+1; J < arrSize; J++){
        if(subArr[J] < smallestElement){
            smallestElement = subArr[J];
            position = J;
        }
    }
    return position;
}
#endif

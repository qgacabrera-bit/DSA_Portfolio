#ifndef BUBBLESORT_H
#define BUBBLESORT_H
template <typename T>
void bubbleSort(T arr[], const int arrSize){
    T temp;
    for(int i = 0; i < arrSize; i++){
        for(int j = i+1; j < arrSize; j++){
            if(arr[j] < arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
#endif

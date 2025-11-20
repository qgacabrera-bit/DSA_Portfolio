#ifndef TABLE_8_2_SHELLSORT_H
#define TABLE_8_2_SHELLSORT_H
void shellSort(int arr[], const int size){
    int temp, back;
    for(int interval = size/2; interval > 0; interval = interval/2){
        for(int i = interval; i < size; i += interval){
            temp = arr[i];
            back = i - interval;

            while(temp <= arr[back] && back >= 0){
                arr[back+interval] = arr[back];
                back = back - interval;
            }
            arr[back+interval] = temp;
        }
    }
}
#endif //TABLE_8_2_SHELLSORT_H

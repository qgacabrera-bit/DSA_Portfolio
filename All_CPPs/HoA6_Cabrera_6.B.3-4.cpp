#include <iostream>

int bisearch(int array[], int num, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low)/2;


    if (array[mid] == num)
      return mid;


    if (array[mid] > num)
      return bisearch(array, num, low, mid-1);


    return bisearch(array, num, mid+1, high);
  }

  return -1;
}

int main(void) {
  int array[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
  int num = 8;
  int n = sizeof(array)/sizeof(array[0]);
  int result = bisearch(array, num, 0, n-1);
  if (result == -1)
    std::cout<< "Element is not found";
  else
     std::cout<< "Element is found at index: "<<result;
}

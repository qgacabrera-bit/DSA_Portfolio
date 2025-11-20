#include <iostream>
#include <cstdlib>
#include <time.h>

const int max_size = 100;

int main() {
    int unsortedList[max_size];
    srand(time(0));
    for(int i = 0; i < max_size; i++){
        unsortedList[i] = rand() % 100;
        std::cout << unsortedList[i] << " ";
    }
    return 0;
}

#include "Linear Search for Arrays.h"

const int max_size = 999;

int main() {
    int dataset[max_size];
    srand(time(0));
    for(int i = 0; i < max_size; i++){
        dataset[i] = rand() % 100;
        //std::cout << dataset[i] << " ";
    }

    std::cout << std::endl;

    int find = 10;
    linearSearch(max_size, dataset, find);

    return 0;
}

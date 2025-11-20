#include <iostream>
#include "queue.h"
#include <string.h>


int main (){
    std::string CPE21S4[5] = {"Gabriel", "Base", "Lynn", "Tamayo", "Ycay"};
    Queue <std::string> queue1;
    for(int i = 0; i < 5; i++){
        queue1.enqueue(CPE21S4[i]);
    }
    queue1.display();
    return 0;
}

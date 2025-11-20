#include <iostream>
#include "queue_supplementary.h"
#include <string>

class Job{
public:
    std::string Name;
    int Pages;
    int id = 0;
};

template <typename T>
class Printer{
public:
    void add_Queue(){
        Queue <std::string> q; 
        Job j;
        char choice='Y';
        while (choice == 'Y' || choice == 'y') {
            std::cout << "Enter your name: ";
            std::cin >> j.Name;
            std::cout << "Number of pages you want to print: ";
            std::cin >> j.Pages;
            std::string concan = std::to_string(++j.id) + "\t\t\t" + j.Name + "\t\t\t" + std::to_string(j.Pages);
            q.enqueue(concan);
            std::cout << "Are you done? Do you want to add more? (Y/N)";
            std::cin >> choice;
        }
        std::cout << "ID\t\t\tName\t\t\tPages" <<std::endl;
        q.display();
    }
};



int main()
{
    Printer<Job> print;
    print.add_Queue();
}

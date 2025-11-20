#include <iostream>
#include "binaryTree.h"

int main() {
    auto *root = createNodeBT(2);

    insertNode(root,2,3);
    insertNode(root,3,9);
    insertNode(root,9,18);
    insertNode(root,2,0);
    insertNode(root,0,1);
    insertNode(root,9,4);
    insertNode(root,4,5);

    std::cout << "PRE-ORDER" << std::endl;
    preBT(root);
    std::cout << std::endl;
    std::cout << "POST-ORDER"<< std::endl;
    postBT(root);
    std::cout << std::endl;
    std::cout << "IN-ORDER"<< std::endl;
    inBT(root);
    return 0;
}


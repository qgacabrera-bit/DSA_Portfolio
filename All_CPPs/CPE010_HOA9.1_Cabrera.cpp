#include "Trees.h"
int main() {
    treeNode<char>* root = createNode('A');

    treeNode<char>* B = createNode('B');
    root->firstChild = B;
    treeNode<char>* C = createNode('C');
    B->nextSibling = C;
    treeNode<char>* D = createNode('D');
    C->nextSibling = D;
    treeNode<char>* E = createNode('E');
    D->nextSibling = E;
    treeNode<char>* F = createNode('F');
    E->nextSibling = F;
    treeNode<char>* G = createNode('G');
    F->nextSibling = G;

    treeNode<char>* H = createNode('H');
    D->firstChild = H;

    treeNode<char>* I = createNode('I');
    E->firstChild = I;
    treeNode<char>* J = createNode('J');
    I->nextSibling = J;

    treeNode<char>* K = createNode('K');
    F->firstChild = K;
    treeNode<char>* L = createNode('L');
    K->nextSibling = L;
    treeNode<char>* M = createNode('M');
    L->nextSibling = M;

    treeNode<char>* N = createNode('N');
    G->firstChild = N;

    treeNode<char>* P = createNode('P');
    J->firstChild = P;
    treeNode<char>* Q = createNode('Q');
    P->nextSibling = Q;

    std::cout << "Pre-order" << std::endl;
    preorder(root);

    std::cout << std::endl;
    std::cout << "Post-order" << std::endl;
    postorder(root);

    std::cout << std::endl;
    std::cout << "Create new child O" << std::endl;
    insertChild(F->nextSibling, 'G', 'O');
    std::cout << "Find new child O" << std::endl;
    findData(root, 'O', 1);
    findData(root, 'O', 2);
    return 0;
}

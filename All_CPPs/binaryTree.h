#ifndef ILO_C_BINARYTREE_H
#define ILO_C_BINARYTREE_H
#include <iostream>

template <typename T>
class binaryNode{
public:
    T element;
    binaryNode *left;
    binaryNode *right;
};

template <typename T>
binaryNode<T> *createNodeBT(T newElement){
    auto *newNode = new binaryNode<T>;
    newNode->element = newElement;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

template <typename T>
void insertNode(binaryNode<T> *root, T ancestor, T desc){
    if(root==nullptr) return;

    if(root->element == ancestor){
        if(root->left!=nullptr && root->right!=nullptr){
            std::cout << "Cannot add new node.\n\n";
            return;
        }
        if(desc<ancestor){
            if(root->left!=nullptr){
                std::cout << "Cannot add new node.\n\n";
                return;
            } else {
                root->left = createNodeBT(desc);
                return;
            }
        } else {
            if(root->right!=nullptr){
                std::cout << "Cannot add new node.\n\n";
                return;
            } else {
                root->right = createNodeBT(desc);
                return;
            }
        }
    }
    insertNode(root->left, ancestor, desc);
    insertNode(root->right, ancestor, desc);
}

template <typename T>
void preBT(binaryNode<T> *root){
    if(root==nullptr) return;
    std::cout << root->element << " ";
    preBT(root->left);
    preBT(root->right);
}

template <typename T>
void postBT(binaryNode<T> *root){
    if(root==nullptr) return;
    postBT(root->left);
    postBT(root->right);
    std::cout << root->element << " ";
}

template <typename T>
void inBT(binaryNode<T> *root){
    if(root==nullptr) return;
    inBT(root->left);
    std::cout << root->element << " ";
    inBT(root->right);
}

#endif

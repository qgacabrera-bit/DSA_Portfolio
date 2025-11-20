#ifndef ILO_A_TREES_H
#define ILO_A_TREES_H
#include <iostream>

template <typename T>
class treeNode{
public:
    T element;
    treeNode* firstChild;
    treeNode* nextSibling;
};

template <typename T>
treeNode<T>* createNode(T newData){
    treeNode<T>* newNode = new treeNode<T>;
    newNode->element = newData;
    newNode->firstChild = nullptr;
    newNode->nextSibling = nullptr;
    return newNode;
}

template <typename T>
void preorder(treeNode<T> *p){
    if(p != NULL){
        std::cout << p->element << " ";
        preorder(p->firstChild);
        preorder(p->nextSibling);
    }
}

template <typename T>
void postorder(treeNode<T> *p){
    if(p != NULL){
        postorder(p->firstChild);
        postorder(p->nextSibling);
        std::cout << p->element << " ";
    }
}

template <typename T>
void insertChild(treeNode<T> *p, T parent, T childElement){
    treeNode<T> *currentNode = p;

    if(currentNode->element == parent){
        if(currentNode->firstChild!=nullptr){
            currentNode = currentNode->firstChild;
            while(currentNode->nextSibling!=nullptr){
                currentNode = currentNode->nextSibling;
            }
            currentNode->nextSibling = createNode(childElement);
            return;
        } else {
            currentNode->firstChild = createNode(childElement);
            return;
        }
    }
    insertChild(p->firstChild, parent, childElement);
    insertChild(p->nextSibling, parent, childElement);
}

template <typename T>
void preorderFind(treeNode<T> *p, T key){
    if(p==nullptr) return;

    if(p->element==key){
        std::cout << key << " was found!\n";
        return;
    }
    preorderFind(p->firstChild, key);
    preorderFind(p->nextSibling, key);
}

template <typename T>
void postorderFind(treeNode<T> *p, T key){
    if(p==nullptr) return;
    auto *currentNode = p->firstChild;
    while(currentNode!= nullptr){
        postorderFind(currentNode, key);
        currentNode = currentNode->nextSibling;
    }
    if(p->element==key){
        std::cout << key << " was found!\n";
        return;
    }
}

template <typename T>
void findData(treeNode<T> *p, T key, int choice){
    if(choice==1){
        preorderFind(p, key);
        return;
    }
    if(choice==2){
        postorderFind(p, key);
        return;
    }
}
#endif

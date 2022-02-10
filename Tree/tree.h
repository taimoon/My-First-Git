#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
typedef int T;
void printFunc(T data){
    printf("%d", data);
}
typedef struct node{
    T data;
    struct node *parent;
    struct node *left;
    struct node *right;
}node;
typedef struct node* nodePtr;
void printBinaryTree(nodePtr tree, int space, int height);
void printInorder(node *tree);
void printPostorder(nodePtr tree);
void printPreorder(nodePtr tree);
nodePtr searchNode(node *tree, T key);
nodePtr createNode(T val);
void insertion(nodePtr *tree, T val);
void insertNode(nodePtr *tree, nodePtr *newNode);
nodePtr maxNode(node* tree){
    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}
nodePtr minNode(node* tree){
    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}
void printBinaryTree(nodePtr tree, int space, int height){
    if(tree == NULL)
        return;
    space += height;
    printBinaryTree(tree->right, space, height);
    printf("\n");
    for(int i = height; i < space; ++i)
        printf(" ");
    printFunc(tree->data);
    printf("\n");
    printBinaryTree(tree->left, space, height);
}
void printInorder(node *tree){
    if(tree != NULL){
        printInorder(tree->left);
        printFunc(tree->data);printf(" ");
        printInorder(tree->right);
    }
}
void printPostorder(nodePtr tree){
    if(tree != NULL){
        printPostorder(tree->left);
        printPostorder(tree->right);
        printFunc(tree->data);printf(" ");
    }
}
void printPreorder(nodePtr tree){
    if(tree != NULL){
        printFunc(tree->data);printf(" ");
        printPreorder(tree->left);
        printPreorder(tree->right);
    }
}
nodePtr searchNode(node *tree, T key){
    while(tree != NULL && tree->data != key){
            if(key < tree->data)
                tree = tree->left;
            else
                tree = tree->right;
    }
    return tree;
}
nodePtr createNode(T val){
    nodePtr temp = (nodePtr)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}
void insertion(nodePtr *tree, T val){
    nodePtr newNode = createNode(val);
    insertNode(tree, &newNode);
};
void insertNode(nodePtr *tree, nodePtr *newNode){
    nodePtr curr = *tree;
    nodePtr currParent = NULL;
    while(curr != NULL){
        currParent = curr;
        if((*newNode)->data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    (*newNode)->parent = currParent;
    if(currParent == NULL)
        *tree = (*newNode);
    else if((*newNode)->data < currParent->data)
        currParent->left = *newNode;
    else
        currParent->right = *newNode;
}
void transplantNode(nodePtr *tree, nodePtr *oldNode, nodePtr *newNode){
    if((*oldNode)->parent == NULL)
        *tree = *newNode;
    else if((*oldNode)->parent->left == *oldNode)
        (*oldNode)->parent->left = *newNode;
    else
        (*oldNode)->parent->right = *newNode;
    if(*newNode != NULL)
        (*newNode)->parent = (*oldNode)->parent;
}
void deletion(nodePtr *tree, T key){
    nodePtr delNode = searchNode(*tree, key);
    if(delNode != NULL)
        deleteNode(tree, &delNode);
}
void deleteNode(nodePtr *tree, nodePtr *delNode){
    if((*delNode)->left == NULL)
        transplantNode(tree, delNode, &((*delNode)->right));
    else if((*delNode)->right == NULL)
        transplantNode(tree, delNode, &((*delNode)->left));
    else{
        nodePtr temp = minNode((*delNode)->right);
        if(temp->parent != *delNode){
            transplantNode(tree, &temp, &(temp->right));
            temp->right = (*delNode)->right;
            temp->right->parent = temp;
        }
        transplantNode(tree, delNode, &temp);
        temp->left = (*delNode)->left;
        temp->left->parent = temp;
    }
    free(*delNode);
}
#endif // TREE_H_INCLUDED

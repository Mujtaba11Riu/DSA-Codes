#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <conio.h>
using namespace std;

class TreeNode

{

private:
    int key;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int key);

    int getKey();
    void setKey(int key);

    TreeNode* getLeft();
    TreeNode* getRight();

    void setLeft(TreeNode* left);
    void setRight(TreeNode* right);
};

class Tree
{
private:
    TreeNode* root;

    void inorder(TreeNode* n);

public:
    Tree();

    bool isEmpty();

    TreeNode* findParent(int key);
    TreeNode* findParent2(int key);

    void insert(int key);
    void display();

    TreeNode* search(int key);
    void removeNode(int toRemove);
};

#endif

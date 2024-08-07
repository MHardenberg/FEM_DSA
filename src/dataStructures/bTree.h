#ifndef tree_H
#define tree_H

#include <stdlib.h>
struct BTreeNode;

typedef struct BTreeNode {
    int data;
    struct BTreeNode *left, *right;
} BTreeNode;

typedef int (*BTreeOrderingFunction)(BTreeNode *newNode, BTreeNode *currentNode);

typedef struct BTree {
    BTreeNode *origin;
    BTreeOrderingFunction OrderingFun_ptr;
    size_t size;
} BTree;

BTree *create_BTree(BTreeOrderingFunction fun_ptr);

// Add nodes
int BTree_addNode(BTree *bTree, int data);

// walk nodes
BTreeNode** BTree_walk(BTree *bTree);

// free nodes
void freeBTree(BTree *tree);

#endif // !tree_H

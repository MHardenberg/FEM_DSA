#ifndef tree_H
#define tree_H

#include <cstddef>
#include <stdlib.h>

typedef struct BTreeNode {
    int data;
     BTreeNode *parent,
    *left, 
    *right;
} BTreeNode;

typedef struct BTree {
    BTreeNode *origin;
    size_t size;
} BTree;


static void step(BTreeNode *current, BTreeNode* list[], size_t idx) {
    list[idx] = current;
    if (current->left) {
        step(current->left, list, idx + 1);
    }
    if (current->right) {
        step(current->right, list, idx + 1);
    }
}


BTreeNode** BTree_walk(BTree *tree) {
    if (tree->origin == NULL) {
        return NULL;
    }

    BTreeNode **nodeList = (BTreeNode**)malloc(tree->size);
    size_t idx = 0;
    step(tree->origin, nodeList, idx);

    return nodeList;
}


void freeBTree(BTree *tree) {
    BTreeNode** nodeList = BTree_walk(tree);
    for (size_t i = 0; i < tree->size; ++i) {
        free(nodeList[i]);
    }
}

#endif // !tree_H

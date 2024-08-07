#include "bTree.h"

BTree *create_BTree(BTreeOrderingFunction fun_ptr) {
    BTree *bTree = (BTree*)malloc(sizeof(BTree));
    if (bTree == NULL) {
        return NULL;
    }

    bTree->origin = NULL;
    bTree->OrderingFun_ptr = fun_ptr;
    bTree->size = 0;

    return bTree;
}


static void _appendNode(BTree* bTree,
        BTreeNode *newNode, BTreeNode *currentNode) {

    int odering = (*bTree->OrderingFun_ptr)(newNode, currentNode);
    if (odering < 0) {
        if (currentNode->left == NULL) {
            currentNode->left = newNode;
            bTree->size++;
            return;
        }
        else {
            _appendNode(bTree, newNode, currentNode->left);
            return;
        }

    }

    if (odering > 0) {
        if (currentNode->right == NULL) {
            currentNode->right = newNode;
            bTree->size++;
            return;
        }
        else {
            _appendNode(bTree, newNode, currentNode->right);
            return;
        }
    }
    return;
}


// Add nodes
int BTree_addNode(BTree *bTree, int data) {
    if (bTree == NULL) {
        return 1;
    }
    
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    if (node == NULL) {
        return 1;
    }

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    if (bTree->origin == NULL) {
        bTree->origin = node;
        bTree->size++;
        return 0;
    }

    _appendNode(bTree, node, bTree->origin);
    return 0;
}


// walk nodes
static void _stepNode(BTreeNode *current, BTreeNode* list[], size_t *idx) {
    if (current == NULL) {
        return;
    }

    list[*idx] = current;
    ++(*idx);

    if (current->left) {
        _stepNode(current->left, list, idx);
    }
    if (current->right) {
        _stepNode(current->right, list, idx);
    }
}


BTreeNode** BTree_walk(BTree *bTree) {
    if (bTree->origin == NULL) {
        return NULL;
    }

    BTreeNode **nodeList = (BTreeNode**)malloc(bTree->size * sizeof(BTreeNode*));
    size_t idx = 0;
    _stepNode(bTree->origin, nodeList, &idx);

    return nodeList;
}


// free nodes
void freeBTree(BTree *tree) {
    BTreeNode** nodeList = BTree_walk(tree);
    for (size_t i = 0; i < tree->size; ++i) {
        free(nodeList[i]);
    }

    free(nodeList);
    free(tree);
}

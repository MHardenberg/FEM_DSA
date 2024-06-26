#include "llist.h"

struct LList *createLList() {
    struct LList *list_ptr = malloc(sizeof(struct LList));
    if (list_ptr == NULL) {
        return NULL;
    }

    list_ptr->head_ptr = NULL;
    list_ptr->tail_ptr = NULL;
    list_ptr->length = 0;
    return list_ptr;
}

struct Node *LListGetItem(struct LList *list_ptr, size_t pos){
    if (list_ptr == NULL) {
        return NULL;
    }

    if ((pos >= list_ptr->length)) {
        fprintf(stderr, "LListInsertNode Error: Index out of bounds.\n");
        return NULL;
    }
    
    struct Node *node_ptr = list_ptr->head_ptr;
    for (size_t i = 0; i < pos; ++i){
        node_ptr = node_ptr->next;
    }
    return node_ptr;
}


int LListAppendNode(struct LList *list_ptr, int data) {
    if (list_ptr == NULL) {
        return 1;
    }
    struct Node *new_ptr = malloc(sizeof(struct Node));
    if (new_ptr == NULL) {
        return 1;
    }
    new_ptr->data = data;
    new_ptr->next = NULL;

    if (list_ptr->head_ptr == NULL) {
        list_ptr->head_ptr = new_ptr;
    }

    // link to previous if existing
    struct Node *prev_ptr = list_ptr->tail_ptr;
    if (prev_ptr) {
        prev_ptr->next = new_ptr;
    }

    // make tail
    list_ptr->tail_ptr = new_ptr;
    list_ptr->length++;
    return 0;
}


int LListInsertNode(struct LList *list_ptr, size_t pos, int data) {
    if (pos > list_ptr->length) {
        fprintf(stderr, "LListInsertNode Error: Index out of bounds.\n");
        return 1;
    }
    
    struct Node *new_ptr = malloc(sizeof(struct Node));
    if (new_ptr == NULL) {
        return 1;
    }
    new_ptr->data = data;

    // prepend
    if (pos == 0) {
        new_ptr->next = list_ptr->head_ptr;
        list_ptr->head_ptr = new_ptr;

        if (list_ptr->tail_ptr == NULL){
            list_ptr->tail_ptr = new_ptr;
        }

        list_ptr->length++;
        return 0;
    }

    // insert
    struct Node *prev_ptr = LListGetItem(list_ptr, pos-1);
    new_ptr->next = prev_ptr->next;
    prev_ptr->next = new_ptr;
    
    if (new_ptr->next == NULL) {
        list_ptr->tail_ptr = new_ptr;
    }

    list_ptr->length++;
    return 0;
}


int LListDeleteNode(struct LList *list_ptr, size_t pos) {
    if (pos >= list_ptr->length) {
        fprintf(stderr, "LListDeleteNode Error: Index out of bounds.\n");
        return 1;
    }

    struct Node *node_ptr = list_ptr->head_ptr;
    struct Node *prev_ptr = NULL;

    for (size_t i = 0; i < pos; ++i) {
        prev_ptr = node_ptr;
        node_ptr = node_ptr->next;
    }

    if (prev_ptr != NULL) {
        prev_ptr->next = node_ptr->next;
    } else {
        list_ptr->head_ptr = node_ptr->next;
    }

    if (node_ptr->next == NULL) {
        list_ptr->tail_ptr = prev_ptr;
    }

    free(node_ptr);
    list_ptr->length--;
    return 0;
}

void freeLList(struct LList *list_ptr) {
    if (list_ptr == NULL) {
        return;
    }

    struct Node *current = list_ptr->head_ptr;
    struct Node *next;
    while (current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    free(list_ptr);
}

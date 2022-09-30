//
// Created by xed22 on 29.09.2022.
//

#include "node.h"

node *nextLinkNode(node n) {
    return n.next;
}

void tieNext(node *current, node *other) {
    current->next = other;
}

int getValue(node n) {
    return n.value;
}

int *getLinkValue(node *n) {
    return &(n->value);
}

node nextNode(node n) {
    return *(n.next);
}

void freeNode(node *n) {
    if (n->next != NULL)
        free(n->next);

    if (n != NULL)
        free(n);
}

node *createEmptyNode() {
    return createNodeWithValue(0);
}

void setValue(node *n, int value) {
    n->value = value;
}

node *createNodeWithValue(int value) {
    node *n = (node *) malloc(sizeof(node));
    n->value = value;
    n->next = NULL;

    return n;
}

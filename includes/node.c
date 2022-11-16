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
    return createNodeWithValueAndKey('0', 0);
}

void setValue(node *n, int value) {
    n->value = value;
}

node *createNodeWithValueAndKey(char key, int value) {
    node *n = (node *) malloc(sizeof(node));
    n->value = value;
    n->key = key;
    n->next = NULL;

    return n;
}

void setKey(node *n, char key) {
    assert(n != NULL);
    n->key = key;
}

char getKey(node n) {
    return n.key;
}

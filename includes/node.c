//
// Created by xed22 on 29.09.2022.
//

#include "node.h"

node *nextLinkNode(node n) {
    return n.next;
}

void tieNode(node *current, node *other) {
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
    n->next = NULL;
}

node createEmptyNode() {
    return (node) {0, NULL};
}

void setValue(node *n, int value) {
    n->value = value;
}

node createNodeWithValue(int value) {
    return (node) {value, NULL};
}

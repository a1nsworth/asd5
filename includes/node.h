//
// Created by xed22 on 29.09.2022.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} node;

int getValue(node n);

int *getLinkValue(node *n);

void setValue(node *n, int value);

node *nextLinkNode(node n);

node nextNode(node n);

void tieNode(node *current, node *other);

void freeNode(node *n);

node createEmptyNode();

node createNodeWithValue(int value);

#endif //LIST_NODE_H

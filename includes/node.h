//
// Created by xed22 on 29.09.2022.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef struct node {
    char key;
    int value;
    struct node *next;
} node;

int getValue(node n);

char getKey(node n);

int *getLinkValue(node *n);

void setValue(node *n, int value);

void setKey(node *n, char key);

node *nextLinkNode(node n);

node nextNode(node n);

void tieNext(node *current, node *other);

void freeNode(node *n);

node *createEmptyNode();

node *createNodeWithValueAndKey(char key, int value);

#endif //LIST_NODE_H

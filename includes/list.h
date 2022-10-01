//
// Created by xed22 on 29.09.2022.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "node.h"

typedef struct list {
    node *begin;
    node *end;
    size_t size;
} list;

bool isEmpty(list l);

size_t size(list l);

list createEmptyList();

void pushBack(list *l, int value);

void pushFront(list *l, int value);

void inputList(list *l, size_t n);

void outputList(list l);

int getElement(list l, size_t position);

node getNode(list l, size_t position);

node *getLinkNode(list l, size_t position);

void add(list *l, int value, size_t position);

void freeList(list *l);

void copyList(list *l1, list *l2);

list createNodeFromArray(int *a, size_t n);

bool isEqualLists(list l1, list l2);

list constructPolynomial(list l1, list l2);

void popBack(list *l);

void popFront(list *l);

node *getLinkFront(list l);

node *getLinkBack(list l);

node getFront(list l);

node getBack(list l);

void pop(list *l, size_t position);

void outputPolynomial(list l);

#endif //LIST_LIST_H

//
// Created by Daniel on 08.11.2022.
//

#ifndef LIST_TABLE_H
#define LIST_TABLE_H

#include "list.h"

typedef struct table {
    list list;
    node *currentNode;
} table;

typedef struct keyAndValue {
    char key;
    int value;
} keyAndValue;

size_t getSize_table(table t);

bool isEmpty_table(table t);

node getCurrentNode_table(table t);

node *getLinkCurrentNode_table(table *t);

void moveCurrentNodeToNext(table *t);

table createEmptyTable();

node *getLinkNodeByIndex_table(table t, size_t position);

bool isContainKey(table t, char key);

node *getLinkNodeByKey(table *t, char key);

void setValueByKey_table(table *t, char key, int value);

int getIndexForInsert(table t, char key);

void add_table(table *t, char key, int value);

void addKeyAndValue_table(table *t, keyAndValue v);

void popByKey(table *t, char key);

table *inputTable(size_t n);

void outputTable(table t);

table *createFromArray(keyAndValue *a, size_t n);

bool areEqualsTables(table t1, table t2, bool (*binaryPredicate)(node, node));

void freeTable(table *t);

#endif //LIST_TABLE_H

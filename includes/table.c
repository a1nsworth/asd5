//
// Created by Daniel on 08.11.2022.
//

#include "table.h"

size_t getSize_table(table t) {
    return t.list.size;
}

bool isEmpty_table(table t) {
    return getSize_table(t) == 0;
}

node getCurrentNode_table(table t) {
    return *(t.currentNode);
}

node *getLinkCurrentNode_table(table *t) {
    return t->currentNode;
}

void moveCurrentNodeToNext(table *t) {
    t->currentNode = t->currentNode->next;
}

table createEmptyTable() {
    list l = createEmptyList();
    node *currentNode = l.begin;

    return (table) {l, currentNode};
}

node *getLinkNodeByIndex_table(table t, size_t position) {
    if (getSize_table(t) <= position) {
        fprintf(stderr, "out of range");
        exit(2);
    }

    for (register size_t i = 0; i < position; ++i) {
        moveCurrentNodeToNext(&t);
    }

    return getLinkCurrentNode_table(&t);
}

bool isContainKey(table t, char key) {
    if (isEmpty_table(t))
        return false;

    int left = 0;
    int right = getSize_table(t) - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        node *n = getLinkNodeByIndex_table(t, middle);

        if (getKey(*n) > key) {
            right = middle - 1;
        } else if (getKey(*n) < key) {
            left = middle + 1;
        } else
            return true;
    }

    return false;
}

node *getLinkNodeByKey(table *t, char key) {
    int left = 0;
    int right = getSize_table(*t) - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        node *n = getLinkNodeByIndex_table(*t, middle);

        if (getKey(*n) > key) {
            left = middle + 1;
        } else if (getKey(*n) < key) {
            right = middle - 1;
        } else {
            return n;
        }
    }

    fprintf(stderr, "element not found");
    return createEmptyNode();
}

void setValueByKey_table(table *t, char key, int value) {
    setValue(getLinkNodeByKey(t, key), value);
}

int getIndexForInsert(table t, char key) {
    int left = -1;
    int right = getSize_table(t);
    while (right - left > 1) {
        int middle = left + (right - left) / 2;
        node n = *getLinkNodeByIndex_table(t, middle);

        getKey(n) >= key ? (right = middle) : (left = middle);
    }

    return right;
}

void add_table(table *t, char key, int value) {
    if (!isEmpty_table(*t) && !isContainKey(*t, key)) {
        int indexForInsert = getIndexForInsert(*t, key);

        if (indexForInsert == 0) {
            pushFront(&(t->list), key, value);
            t->currentNode = t->list.begin;
        } else if (indexForInsert == getSize_table(*t)) {
            pushBack(&(t->list), key, value);
        } else {
            node *lastNode = getLinkNodeByIndex_table(*t, indexForInsert);
            node *nodeForInsert = createNodeWithValueAndKey(key, value);
            node *nextNode = lastNode->next;

            lastNode->next = nodeForInsert;
            nodeForInsert->next = nextNode;

            t->list.size++;
        }
    } else if (isEmpty_table(*t)){
        pushFront(&(t->list), key, value);
        t->currentNode = t->list.begin;
    }
}

table *inputTable(const size_t n) {
    table *t = (table *) malloc(sizeof(table));
    *t = createEmptyTable();

    for (register size_t i = 0; i < n; ++i) {
        char key;
        int value;
        scanf("%c %d", &key, &value);

        add_table(t, key, value);
    }

    return t;
}

void outputTable(table t) {
    while (t.currentNode != NULL) {
        node currentNode = getCurrentNode_table(t);
        printf("{%c, %d} ", getKey(currentNode), getValue(currentNode));

        moveCurrentNodeToNext(&t);
    }
}

void popByKey(table *t, const char key) {
    if (!isEmpty_table(*t) && isContainKey(*t, key)) {
        int indexForDelete = getIndexForInsert(*t, key);

        if (indexForDelete == 0) {
            t->currentNode = t->list.begin->next;
            popFront(&(t->list));
        } else if (indexForDelete == getSize_table(*t) - 1) {
            popBack(&(t->list));
        } else {
            node *lastNode = getLinkNodeByIndex_table(*t, indexForDelete - 1);
            node *nodeForDelete = lastNode->next;
            node *nextNode = nodeForDelete->next;

            lastNode->next = nextNode;

            free(nodeForDelete);

            t->list.size--;
        }
    }
}

table *createFromArray(keyAndValue *a, const size_t n) {
    table *t = (table *) malloc(sizeof(table));
    *t = createEmptyTable();

    for (register size_t i = 0; i < n; ++i) {
        addKeyAndValue_table(t, a[i]);
    }

    return t;
}

bool areEqualsTables(table t1, table t2, bool (*binaryPredicate)(node, node)) {
    if (getSize_table(t1) != getSize_table(t2))
        return false;

    for (register size_t i = 0; i < getSize_table(t1); ++i) {
        if (!binaryPredicate(getCurrentNode_table(t1), getCurrentNode_table(t2)))
            return false;

        moveCurrentNodeToNext(&t1);
        moveCurrentNodeToNext(&t2);
    }


    return true;
}

void addKeyAndValue_table(table *t, keyAndValue v) {
    if (!isEmpty_table(*t) && !isContainKey(*t, v.key)) {
        int indexForInsert = getIndexForInsert(*t, v.key);

        if (indexForInsert == 0) {
            pushFront(&(t->list), v.key, v.value);
            t->currentNode = t->list.begin;
        } else if (indexForInsert == getSize_table(*t)) {
            pushBack(&(t->list), v.key, v.value);
        } else {
            node *lastNode = getLinkNodeByIndex_table(*t, indexForInsert);
            node *nodeForInsert = createNodeWithValueAndKey(v.key, v.value);
            node *nextNode = lastNode->next;

            lastNode->next = nodeForInsert;
            nodeForInsert->next = nextNode;

            t->list.size++;
        }
    } else if (isEmpty_table(*t)) {
        pushFront(&(t->list), v.key, v.value);
        t->currentNode = t->list.begin;
    }
}

void freeTable(table *t) {
    freeList(&(t->list));
}

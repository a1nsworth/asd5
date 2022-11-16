//
// Created by xed22 on 29.09.2022.
//

#include "list.h"

list createEmptyList() {
    return (list) {NULL, NULL, 0};
}

bool isEmpty(list l) {
    return size(l) == 0;
}

void pushBack(list *l, char key, int value) {
    node *n = createNodeWithValueAndKey(key, value);
    if (isEmpty(*l)) {
        l->begin = n;
        l->end = n;
    } else {
        tieNext(l->end, n);
        l->end = n;
    }

    l->size++;
}

size_t size(list l) {
    return l.size;
}

void inputList(list *l, size_t n) {
    while (n > 0) {
        int value;
        char key;
        scanf("%c %d", &key, &value);
        pushBack(l, key, value);

        n--;
    }
}

void outputList(list l) {
    if (!isEmpty(l)) {
        node *current = l.begin;
        for (register size_t i = 0; i < size(l); ++i) {
            printf("%c | %d", getKey(*current), getValue(*current));

            if (current->next != NULL)
                current = current->next;
        }
    }
}

void pushFront(list *l, char key, int value) {
    node *n = createNodeWithValueAndKey(key, value);
    if (isEmpty(*l)) {
        l->begin = n;
        l->end = n;
    } else {
        n->next = l->begin;
        l->begin = n;
    }

    l->size++;
}

int getElement(list l, size_t position) {
    assert(position + 1 <= size(l));

    node n = *(l.begin);
    while (position > 0) {
        n = *(n.next);

        position--;
    }

    return n.value;
}

node getNode(list l, size_t position) {
    assert(position + 1 <= size(l));

    node n = *(l.begin);
    while (position > 0) {
        n = *(n.next);

        position--;
    }

    return n;
}

void add(list *l, char key, int value, size_t position) {
    if (position == 0) {
        pushFront(l, key, value);
    } else if (position == size(*l)) {
        pushBack(l, key, value);
    } else {
        node *last = getLinkNode(*l, position - 1);
        node *next = getLinkNode(*l, position);
        node *current = createNodeWithValueAndKey(key, value);

        tieNext(last, current);
        tieNext(current, next);

        l->size++;
    }
}

node *getLinkNode(list l, size_t position) {
    assert(position + 1 <= size(l));

    node *n = l.begin;
    while (position > 0) {
        n = n->next;

        position--;
    }

    return n;
}

void freeList(list *l) {
    if (!isEmpty(*l)) {
        for (register int position = size(*l) - 1; position >= 0; --position) {
            node *n = getLinkNode(*l, position);
            free(n);
        }
    }

    l->size = 0;
}

void copyList(list *l1, list *l2) {
    size_t n = size(*l2);
    node *valueToAppend = l2->begin;

    if (!isEmpty(*l1))
        freeList(l1);
    while (n > 0) {
        pushBack(l1, valueToAppend->key, valueToAppend->value);

        valueToAppend = nextLinkNode(*valueToAppend);
        n--;
    }

    free(valueToAppend);
}

list createNodeFromArray(int *a, size_t n) {
//    list l = createEmptyList();
//    for (register size_t i = 0; i < n; ++i) {
//        pushBack(&l, a[i]);
//    }
//
//    return l;
}

bool isEqualLists(list l1, list l2) {
    if (size(l1) != size(l2))
        return false;

    if (isEmpty(l1) && isEmpty(l2))
        return true;

    node nodeL1 = *(l1.begin);
    node nodeL2 = *(l2.begin);

    for (register size_t i = 0; i < size(l1); ++i) {
        if (nodeL1.value != nodeL2.value)
            return false;

        if (i + 1 != size(l1)) {
            nodeL1 = nextNode(nodeL1);
            nodeL2 = nextNode(nodeL2);
        }
    }

    return true;
}

list constructPolynomial(list l1, list l2) {
    typedef struct tuple {
        size_t item1;
        size_t item2;
    } tuple;

    list polynomial = createEmptyList();
    node currentForList1 = *(l1.begin);
    node currentForList2 = *(l2.begin);

    size_t sizeL1 = size(l1);
    size_t sizeL2 = size(l2);
    tuple max = {sizeL1 > sizeL2 ? 1 : 2, sizeL1 > sizeL2 ? sizeL1 : sizeL2};
    tuple min = {sizeL1 > sizeL2 ? 2 : 1, sizeL1 > sizeL2 ? sizeL2 : sizeL1};
    for (register size_t i = 0; i < max.item2; ++i) {
        int value = 0;
        if (max.item2 - i <= min.item2) {
            value += getValue(currentForList1) + getValue(currentForList2);

            if (currentForList1.next != NULL)
                currentForList1 = nextNode(currentForList1);
            if (currentForList2.next != NULL)
                currentForList2 = nextNode(currentForList2);
        } else if (max.item1 == 1) {
            value += getValue(currentForList1);

            if (currentForList1.next != NULL)
                currentForList1 = nextNode(currentForList1);
        } else if (max.item1 == 2) {
            value += getValue(currentForList2);

            if (currentForList2.next != NULL)
                currentForList2 = nextNode(currentForList2);
        }

        //pushBack(&polynomial, value);
    }

    return polynomial;
}

void pop(list *l, size_t position) {
    assert(position < size(*l));

    if (!isEmpty(*l)) {
        if (position == 0) {
            popFront(l);
        } else if (position == size(*l) - 1) {
            popBack(l);
        } else {
            node *last = getLinkNode(*l, position - 1);
            node *nodeForPop = last->next;
            node *next = nodeForPop->next;

            free(nodeForPop);
            last->next = next;

            l->size--;
        }
    }
}

node getBack(list l) {
    return *(l.end);
}

node getFront(list l) {
    return *(l.begin);
}

node *getLinkBack(list l) {
    return l.end;
}

node *getLinkFront(list l) {
    return l.begin;
}

void popFront(list *l) {
    if (!isEmpty(*l)) {
        if (size(*l) > 1) {
            free(l->begin);
            l->begin = getLinkNode(*l, 1);
        } else {
            free(l->begin);
            l->begin = NULL;
            l->end = NULL;
        }

        l->size--;
    }
}

void popBack(list *l) {
    if (!isEmpty(*l)) {
        if (size(*l) > 1) {
            free(l->end);
            l->end = getLinkNode(*l, size(*l) - 2);
        } else {
            free(l->begin);
            l->begin = NULL;
            l->end = NULL;
        }

        l->size--;
    }
}

void outputPolynomial(list l) {
    if (!isEmpty(l)) {
        node *current = l.begin;
        for (register size_t i = 0; i < size(l); ++i) {
            int value = getValue(*current);
            if (value != 0)
                printf("(%dx^%d)", value, size(l) - i - 1);
            if (i + 1 != size(l) && value != 0)
                printf("%c", '+');

            if (current->next != NULL)
                current = current->next;
        }
        printf("\b");
    }
}


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

void pushBack(list *l, int value) {
    node *n = createNodeWithValue(value);
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

node *next(list *l) {
    return nextLinkNode(*(l->begin));
}

void inputList(list *l, size_t n) {
    while (n > 0) {
        int value;
        scanf("%d", &value);
        pushBack(l, value);

        n--;
    }
}

void outputList(list l) {
    node n = *(l.begin);
    for (register size_t i = 0; i < size(l); ++i) {
        printf("%d", getValue(n));

        n = *(n.next);
    }
}

void pushFront(list *l, int value) {
    node *n = createNodeWithValue(value);
    if (isEmpty(*l)) {
        l->begin = n;
        l->end = n;
    } else {
        n->next = &(*(l->begin));
        l->end = n;
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

void add(list *l, int value, size_t position) {
    if (position == 0) {
        pushFront(l, value);
    } else if (position == size(*l)) {
        pushBack(l, value);
    } else {
        node *last = getLinkNode(*l, position - 1);
        node *next = getLinkNode(*l, position + 1);
        node *current = createNodeWithValue(value);

        tieNext(last, current);
        tieNext(current, next);

        free(last);
        free(next);
        free(current);

        l->size++;
    }
}

node *getLinkNode(list l, size_t position) {
    assert(position + 1 <= size(l));

    node *n = l.begin;
    while (position > 0) {
        n = nextLinkNode(*n);

        position--;
    }

    return n;
}

void freeList(list *l) {
    if (!isEmpty(*l)) {
        for (register int position = size(*l) - 1; position >= 0; --position) {
            node *n = getLinkNode(*l, position);
            freeNode(n);
        }
    } else {
        freeNode(l->begin);
        freeNode(l->end);
    }

    l->size = 0;
}

void copyList(list *l1, list *l2) {
    size_t n = size(*l2);
    node *x = l1->begin;

    freeList(l1);
    while (n > 0) {
        pushBack(l1, x->value);

        x = nextLinkNode(*x);
        n--;
    }

    free(x);
}

list createNodeFromArray(int *a, size_t n) {
    list l = createEmptyList();
    for (register size_t i = 0; i < n; ++i) {
        pushBack(&l, a[i]);
    }

    return l;
}

bool isEqualLists(list l1, list l2) {
    if (size(l1) != size(l2))
        return false;

    node nodeL1 = *(l1.begin);
    node nodeL2 = *(l2.begin);

    size_t n = size(l1);
    while (n > 0) {
        if (nodeL1.value != nodeL2.value)
            return false;

        if (n != 0) {
            nodeL1 = nextNode(nodeL1);
            nodeL2 = nextNode(nodeL2);
        }

        n--;
    }

    return true;
}

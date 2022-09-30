//
// Created by xed22 on 29.09.2022.
//

#include "list.h"

list createEmptyList() {
    return (list) {NULL, NULL, 0};
}

bool isEmpty(list l) {
    return l.size;
}

void pushBack(list *l, int value) {
    node next = createNodeWithValue(value);
    if (isEmpty(*l))
        l->begin = &next;

    tieToNode(l->end, &next);
    l->end = &next;

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
    node next = createNodeWithValue(value);
    if (isEmpty(*l))
        l->end = &next;

    tieToNode(&next, l->begin);
    l->begin = &next;

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
        node current = createNodeWithValue(value);

        tieToNode(last, &current);
        tieToNode(&current, next);

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

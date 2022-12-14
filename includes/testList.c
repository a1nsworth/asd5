//
// Created by student on 30.09.2022.
//

#include "list.h"

void test_createEmptyList() {
    // Arrange
    list actual;
    list expected = {NULL, NULL, 0};

    // Act
    actual = createEmptyList();

    // Asserts
    assert(actual.begin == expected.end);
    assert(actual.begin == expected.end);
    assert(size(actual) == size(expected));
}

void test_pushBack_emptyList() {
    // Arrange
    int expectedValue = 1;
    list actual = createEmptyList();

    // Act
    pushBack(&actual, 1);

    // Asserts
    assert(actual.begin == actual.end);
    assert(actual.begin->value == expectedValue && actual.end->value == expectedValue);
    assert(actual.begin->next == NULL && actual.end->next == NULL);
    assert(size(actual) == 1);

    freeList(&actual);
}

void test_pushBack_notEmpty() {
    // Arrange
    list actual = createEmptyList();

    // Act
    pushBack(&actual, 1);
    pushBack(&actual, 2);
    pushBack(&actual, 3);
    pushBack(&actual, 4);
    pushBack(&actual, 5);

    // Asserts
    node current = *(actual.begin);

    assert(size(actual) == 5);
    assert(getNode(actual, 0).value == current.value && getNode(actual, 0).next == current.next);
    current = nextNode(current);
    assert(getNode(actual, 1).value == current.value && getNode(actual, 1).next == current.next);
    current = nextNode(current);
    assert(getNode(actual, 2).value == current.value && getNode(actual, 2).next == current.next);
    current = nextNode(current);
    assert(getNode(actual, 3).value == current.value && getNode(actual, 3).next == current.next);
    current = nextNode(current);
    assert(getNode(actual, 4).value == current.value && getNode(actual, 4).next == current.next);

    freeList(&actual);
}

void test_pushBack() {
    test_pushBack_emptyList();
    test_pushBack_notEmpty();
}

void test_getNode() {
    // Arrange
    list actual = createEmptyList();

    // Act
    pushBack(&actual, 1);
    pushBack(&actual, 2);
    pushBack(&actual, 3);
    pushBack(&actual, 4);
    pushBack(&actual, 5);

    // Asserts
    assert(getNode(actual, 0).value == 1);
    assert(getNode(actual, 1).value == 2);
    assert(getNode(actual, 2).value == 3);
    assert(getNode(actual, 3).value == 4);
    assert(getNode(actual, 4).value == 5);

    freeList(&actual);
}

void test_createFromArray() {
    // Arrange
    list actual;
    list expected = createEmptyList();

    // Act
    actual = createNodeFromArray((int[]) {1, 2, 3, 4, 5}, 5);

    pushBack(&expected, 1);
    pushBack(&expected, 2);
    pushBack(&expected, 3);
    pushBack(&expected, 4);
    pushBack(&expected, 5);

    // Asserts
    assert(size(actual) == size(expected));
    assert(getNode(actual, 0).value == getNode(expected, 0).value);
    assert(getNode(actual, 1).value == getNode(expected, 1).value);
    assert(getNode(actual, 2).value == getNode(expected, 2).value);
    assert(getNode(actual, 3).value == getNode(expected, 3).value);
    assert(getNode(actual, 4).value == getNode(expected, 4).value);

    freeList(&actual);
    freeList(&expected);
}

void test_isEqualLists() {
    // Arrange
    list actual;
    list expected = createEmptyList();

    // Act
    actual = createNodeFromArray((int[]) {1, 2, 3, 4, 5}, 5);

    pushBack(&expected, 1);
    pushBack(&expected, 2);
    pushBack(&expected, 3);
    pushBack(&expected, 4);
    pushBack(&expected, 5);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
}

void test_add_begin() {
    // Arrange
    list actual = createNodeFromArray((int[]) {2, 3, 4, 5}, 4);
    list expected = createNodeFromArray((int[]) {1, 2, 3, 4, 5}, 5);

    // Act
    add(&actual, 1, 0);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
}

void test_add_end() {
    // Arrange
    list actual = createNodeFromArray((int[]) {1, 2, 3, 4}, 4);
    list expected = createNodeFromArray((int[]) {1, 2, 3, 4, 5}, 5);

    // Act
    add(&actual, 5, 4);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
}

void test_add_center() {
    // Arrange
    list actual = createNodeFromArray((int[]) {1, 2, 4, 5}, 4);
    list expected = createNodeFromArray((int[]) {1, 2, 3, 4, 5}, 5);

    // Act
    add(&actual, 3, 2);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
}

void test_add() {
    test_add_end();
    test_add_begin();
    test_add_center();
}

void test_copyList() {
    // Arrange
    list actual;
    list listForCopy = createNodeFromArray((int[]) {1, 2, 3, 4, 5}, 5);
    list expected = createNodeFromArray((int[]) {1, 2, 3, 4, 5}, 5);

    // Act
    copyList(&actual, &listForCopy);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
}

void test_constructPolynomial_1() {
    // Arrange
    list p1 = createNodeFromArray((int[]) {1, 2, 3, 4, 5}, 5);
    list p2 = createNodeFromArray((int[]) {1, 2, 3, 4, 5}, 5);
    list expected = createNodeFromArray((int[]) {2, 4, 6, 8, 10}, 5);
    list actual;

    // Act
    actual = constructPolynomial(p1, p2);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
    freeList(&p1);
    freeList(&p2);
}

void test_constructPolynomial_2() {
    // Arrange
    list p1 = createNodeFromArray((int[]) {1, 2, 3, 4}, 4);
    list p2 = createNodeFromArray((int[]) {1, 2, 3, 4, 5}, 5);
    list expected = createNodeFromArray((int[]) {1, 3, 5, 7, 9}, 5);
    list actual;

    // Act
    actual = constructPolynomial(p1, p2);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
    freeList(&p1);
    freeList(&p2);
}

void test_constructPolynomial_3() {
    // Arrange
    list p1 = createNodeFromArray((int[]) {1}, 1);
    list p2 = createNodeFromArray((int[]) {1, 2, 3, 4, 5}, 5);
    list expected = createNodeFromArray((int[]) {1, 2, 3, 4, 6}, 5);
    list actual;

    // Act
    actual = constructPolynomial(p1, p2);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
    freeList(&p1);
    freeList(&p2);
}

void test_constructPolynomial() {
    test_constructPolynomial_1();
    test_constructPolynomial_2();
    test_constructPolynomial_3();
}

void test_popBack_oneElement() {
    // Arrange
    list actual = createNodeFromArray((int[]) {42}, 1);
    list expected = {NULL, NULL, 0};

    // Act
    popBack(&actual);

    // Asserts
    assert(actual.begin == expected.begin);
    assert(actual.end == expected.end);
    assert(actual.size == actual.size);
}

void test_popBack_notOneElement() {
    // Arrange
    list actual = createNodeFromArray((int[]) {1, 2, 3, 4, 5, 6, 7}, 7);
    list expected = createNodeFromArray((int[]) {1, 2, 3, 4, 5, 6}, 6);

    // Act
    popBack(&actual);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
}

void test_popBack() {
    test_popBack_oneElement();
    test_popBack_notOneElement();
}

void test_popFront_oneElement() {
    // Arrange
    list actual = createNodeFromArray((int[]) {42}, 1);
    list expected = {NULL, NULL, 0};

    // Act
    popFront(&actual);

    // Asserts
    assert(actual.begin == expected.begin);
    assert(actual.end == expected.end);
    assert(actual.size == actual.size);
}

void test_popFront_notOneElement() {
    // Arrange
    list actual = createNodeFromArray((int[]) {1, 2, 3, 4, 5, 6, 7}, 7);
    list expected = createNodeFromArray((int[]) {1, 2, 3, 4, 5, 6}, 6);

    // Act
    popBack(&actual);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
}

void test_popFront() {
    test_popFront_oneElement();
    test_popFront_notOneElement();
}

void test_pop_oneElement() {
    // Arrange
    list actual = createNodeFromArray((int[]) {42}, 1);
    list expected = {NULL, NULL, 0};

    // Act
    pop(&actual, 0);

    // Asserts
    assert(actual.begin == expected.begin);
    assert(actual.end == expected.end);
    assert(size(actual) == size(expected));
}

void test_pop_last() {
    // Arrange
    list actual = createNodeFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8}, 8);
    list expected = createNodeFromArray((int[]) {1, 2, 3, 4, 5, 6, 7}, 7);

    // Act
    pop(&actual, 7);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
}

void test_pop_begin() {
    // Arrange
    list actual = createNodeFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8}, 8);
    list expected = createNodeFromArray((int[]) {2, 3, 4, 5, 6, 7, 8}, 7);

    // Act
    pop(&actual, 0);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
}

void test_pop_preLast() {
    // Arrange
    list actual = createNodeFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8}, 8);
    list expected = createNodeFromArray((int[]) {1, 2, 3, 4, 5, 6, 8}, 7);

    // Act
    pop(&actual, 6);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
}

void test_pop_nextBegin() {
    // Arrange
    list actual = createNodeFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8}, 8);
    list expected = createNodeFromArray((int[]) {1, 3, 4, 5, 6, 7, 8}, 7);

    // Act
    pop(&actual, 1);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
}

void test_pop_middle() {
    // Arrange
    list actual = createNodeFromArray((int[]) {1, 2, 3, 42, 5, 6, 7, 8}, 8);
    list expected = createNodeFromArray((int[]) {1, 2, 3, 5, 6, 7, 8}, 7);

    // Act
    pop(&actual, 3);

    // Asserts
    assert(isEqualLists(actual, expected));

    freeList(&actual);
    freeList(&expected);
}

void test_pop() {
    test_pop_oneElement();
    test_pop_last();
    test_pop_begin();
    test_pop_preLast();
    test_pop_nextBegin();
    test_pop_middle();
}

void test_list() {
    test_createEmptyList();
    test_pushBack();
    test_getNode();
    test_isEqualLists();
    test_createFromArray();
    test_add();
    test_copyList();
    test_constructPolynomial();
    test_popBack();
    test_popFront();
    test_pop();
}
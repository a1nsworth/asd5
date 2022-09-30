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

void test_list() {
    test_createEmptyList();
    test_pushBack();
    test_getNode();
    test_isEqualLists();
    //test_createFromArray();
}
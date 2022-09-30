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
}

void test_pushBack() {
    test_pushBack_emptyList();
    test_pushBack_notEmpty();
}

void test_list() {
    test_createEmptyList();
    test_pushBack();
}
//
// Created by student on 30.09.2022.
//
#include <assert.h>

#include "node.h"

void test_createEmptyNode() {
    // Arrange
    node *actual = NULL;
    node expected = {0, NULL};

    // Act
    actual = createEmptyNode();

    // Asserts
    assert(actual->value == expected.value);
    assert(actual->next == expected.next);

    freeNode(actual);
}

void test_createNodeWithValue() {
    // Arrange
    node *actual = NULL;
    node expected = {42, NULL};

    // Act
    actual = createNodeWithValue(42);

    // Asserts
    assert(actual->value == expected.value);
    assert(actual->next == expected.next);

    freeNode(actual);
}

void test_setValue() {
    // Arrange
    node *actual = createEmptyNode();
    node expected = {10, NULL};

    // Act
    setValue(actual, 10);

    // Asserts
    assert(actual->value == expected.value);
    assert(actual->next == expected.next);

    freeNode(actual);
}

void test_getValue() {
    // Arrange
    node *actual = createNodeWithValue(42);
    node expected = {42, NULL};

    // Act
    int value = getValue(*actual);

    // Asserts
    assert(value == expected.value);

    free(actual);
}

void test_tieToNode() {
    // Arrange
    node n = {42, NULL};
    node *actual = createNodeWithValue(42);
    node expected = {42, &n};

    // Act
    tieNext(actual, &n);

    // Asserts
    assert(actual->value == expected.value);
    assert(actual->next->value == expected.next->value);
}

void test_nextNode() {
    // Arrange
    node n = {42, NULL};
    node x = {42, &n};
    node expected = {42, NULL};

    // Act
    node actual = nextNode(x);

    // Asserts
    assert(actual.value == expected.value);
    assert(actual.next == expected.next);
}

void test_getLinkValue() {
    // Arrange
    node x = {42, NULL};
    int *expected = &(x.value);

    // Act
    int *actual = getLinkValue(&x);

    // Asserts
    assert(actual == expected);
}

void test_node() {
    test_createEmptyNode();
    test_setValue();
    test_createNodeWithValue();
    test_tieToNode();
    test_getValue();
    test_nextNode();
    test_getLinkValue();
}
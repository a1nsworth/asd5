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

void test_pushBack_oneElement() {
    // Arrange
    int expectedValue = 1;
    list actual = createEmptyList();

    // Act
    pushBack(&actual, 1);

    // Asserts
    assert(actual.begin->value == expectedValue);
    assert(actual.end->value == expectedValue);

    assert(actual.begin->next = actual.begin->next);

    assert(actual.begin == actual.end);

    assert(size(actual) == 1);
}

void test_pushBack() {
    test_pushBack_oneElement();
}

void test_list() {
    test_createEmptyList();
    test_pushBack();
}
//
// Created by Daniel on 15.11.2022.
//

#include "table.h"

#include <assert.h>

#define EQUAL(item1, item2) item1==item1

bool cmp(node n1, node n2) {
    return getKey(n1) == getKey(n2);
}

void test_add_oneElement() {
    // Arrange
    table actual = createEmptyTable();
    node expected = {'a', 1, NULL};

    // Act
    add_table(&actual, 'a', 1);

    // Asserts
    assert(EQUAL(actual.list.begin->key, expected.key));
    assert(EQUAL(actual.list.begin->value, expected.value));
}

void test_add_oneElementWithSwap() {
    // Arrange
    table actual = createEmptyTable();
    node expected2 = {'b', 2, NULL};
    node expected1 = {'a', 1, &expected2};

    // Act
    add_table(&actual, expected2.key, expected2.value);
    add_table(&actual, expected1.key, expected1.value);

    // Asserts
    assert(EQUAL(actual.list.begin->key, expected1.key));
    assert(EQUAL(actual.list.begin->value, expected1.value));

    assert(EQUAL(actual.list.end->key, expected2.key));
    assert(EQUAL(actual.list.end->value, expected2.value));
}

void test_add_backward() {
    // Arrange
    table actual = createEmptyTable();
    keyAndValue expected[] = {{'f', 6},
                              {'e', 5},
                              {'d', 4},
                              {'c', 3},
                              {'b', 2},
                              {'a', 1}};

    // Act
    addKeyAndValue_table(&actual, expected[0]);
    addKeyAndValue_table(&actual, expected[1]);
    addKeyAndValue_table(&actual, expected[2]);
    addKeyAndValue_table(&actual, expected[3]);
    addKeyAndValue_table(&actual, expected[4]);
    addKeyAndValue_table(&actual, expected[5]);

    // Asserts
    for (register size_t i = 0; i < 6; ++i) {
        assert(EQUAL(getCurrentNode_table(actual).key, expected[i].key));
        assert(EQUAL(getCurrentNode_table(actual).value, expected[i].value));

        moveCurrentNodeToNext(&actual);
    }
}

void test_add_keysAlreadyExists() {
    // Arrange
    table actual = createEmptyTable();
    keyAndValue expected[] = {{'f', 6},
                              {'e', 5},
                              {'d', 4},
                              {'c', 3},
                              {'b', 2},
                              {'a', 1},
                              {'f', 62},
                              {'e', 52},
                              {'d', 42},
                              {'c', 32},
                              {'b', 22},
                              {'a', 12}};

    // Act
    for (register size_t i = 0; i < 12; ++i) {
        addKeyAndValue_table(&actual, expected[i]);
    }

    // Asserts
    assert(getSize_table(actual) == 6);

    for (register size_t i = 0; i < 6; ++i) {
        assert(EQUAL(getCurrentNode_table(actual).key, expected[i].key));
        assert(EQUAL(getCurrentNode_table(actual).value, expected[i].value));

        moveCurrentNodeToNext(&actual);
    }
}

void test_add() {
    test_add_oneElement();
    test_add_oneElementWithSwap();
    test_add_backward();
    test_add_keysAlreadyExists();
}

void test_popByKey_popFromBack() {
    // Arrange
    table *expected = createFromArray((keyAndValue[]) {{'a', 1},
                                                       {'b', 2},
                                                       {'c', 3},
                                                       {'d', 4}}, 4);
    table *actual = createFromArray((keyAndValue[]) {{'a', 1},
                                                     {'b', 2},
                                                     {'c', 3},
                                                     {'d', 4},
                                                     {'e', 5}}, 5);

    // Act
    popByKey(actual, 'e');

    // Asserts
    assert(areEqualsTables(*actual, *expected, cmp));
}

void test_popByKey_popFromFront() {
    // Arrange
    table *expected = createFromArray((keyAndValue[]) {
            {'b', 2},
            {'c', 3},
            {'d', 4},
            {'e', 5}}, 4);
    table *actual = createFromArray((keyAndValue[]) {{'a', 1},
                                                     {'b', 2},
                                                     {'c', 3},
                                                     {'d', 4},
                                                     {'e', 5}}, 5);

    // Act
    popByKey(actual, 'a');

    // Asserts
    assert(areEqualsTables(*actual, *expected, cmp));
}

void test_popByKey_popFromCenter() {
    // Arrange
    table *expected = createFromArray((keyAndValue[]) {
            {'a', 1},
            {'b', 2},
            {'d', 4},
            {'e', 5}}, 4);
    table *actual = createFromArray((keyAndValue[]) {{'a', 1},
                                                     {'b', 2},
                                                     {'c', 3},
                                                     {'d', 4},
                                                     {'e', 5}}, 5);

    // Act
    popByKey(actual, 'c');

    // Asserts
    assert(areEqualsTables(*actual, *expected, cmp));
}

void test_popByKey() {
    test_popByKey_popFromBack();
    test_popByKey_popFromFront();
    test_popByKey_popFromCenter();
}

void test_table() {
    test_add();
    test_popByKey();
}
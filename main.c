#include "includes/testList.c"
#include "includes/testNode.c"


int main() {
    list l1 = createNodeFromArray((int[]) {-2, 3, 4, 5}, 4);
    list l2 = createNodeFromArray((int[]) {1, 2, 3, 4, 5}, 5);
    outputPolynomial(constructPolynomial(l1, l2));

    freeList(&l1);
    freeList(&l2);

    printf("%c", '\n');

    l1 = createNodeFromArray((int[]) {1, 2, 3, 4, 5}, 5);
    l2 = createNodeFromArray((int[]) {1, 2, 3, 4, 5}, 5);
    outputPolynomial(constructPolynomial(l1, l2));

    freeList(&l1);
    freeList(&l2);

    return 0;
}

#include "../src/log/log.h"

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

#include "../src/list/tree.h"

void terminate(int a) {
    closeScreen();
    closeLog();
    exit(0);
}

int main(int argc, char **argv) {
    initLog();
    signal(SIGINT, terminate);

    int i;
    struct Tree tree;
    initTree(&tree);

    for (i = 1; i <= 100; i++) {
        insert(&tree, NULL, i);
    }
    for (i = 200; i > 100; i--) {
        insert(&tree, NULL, i);
    }
    for (i = 201; i <= 300; i++) {
        insert(&tree, NULL, i);
    }
    printf("Tree: %d\n", tree.count);
    printf("Expect 300\n");

    for (i = 0; i <= 200; i += 2) {
        removeId(&tree, i);
    }
    printf("Tree: %d\n", tree.count);
    printf("Expect 200\n");

    for (i = 301; i <= 400; i++) {
        insert(&tree, NULL, i);
    }
    printf("Tree: %d\n", tree.count);
    printf("Expect 300\n");

    for (i = 25; i < 75; i += 2) {
        removeId(&tree, i);
    }
    printf("Tree: %d\n", tree.count);
    printf("Expect 275\n");

    for (i = 100; i >= 0; i--) {
        removeId(&tree, i);
    }
    printf("Tree: %d\n", tree.count);
    printf("Expect 250\n");

    for (i = 300; i >= 0; i--) {
        removeId(&tree, i);
    }
    printf("Tree: %d\n", tree.count);
    printf("Expect 0\n");

    return 0;
}
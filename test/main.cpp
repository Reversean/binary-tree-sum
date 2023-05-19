#include <cstdio>
#include "../core/utils.h"
#include "../core/sum.h"

void experiment_1() {
    printf("Test 1\n");
    printf("=============================\n");
    for (int i = 5; i <= 25; i++) {
        TreeNode *tree = GenerateRandomTree(i);
        sum_tree_sequential(tree);
        sum_tree_pthread(tree);
        sum_tree_openmp(tree);
        printf("=============================\n");
    }
}

void experiment_2() {
    printf("Test 2\n");
    printf("=============================\n");
    TreeNode *tree = GenerateRandomTree(24);
    sum_tree_sequential(tree);
    for (int i = 1; i <= 128; i *= 2) {
        printf("Thread count: %d\n", i);
        sum_tree_pthread(tree, i);
        sum_tree_openmp(tree, i);
        printf("=============================\n");
    }
}

void experiment_3() {
    printf("Test 3\n");
    printf("=============================\n");
    TreeNode *tree = GenerateRandomTree(24);
    for (int i = 1; i <= 20; i++) {
        printf("Iteration: %d\n", i);
        sum_tree_sequential(tree);
        sum_tree_pthread(tree, 8);
        sum_tree_openmp(tree, 8);
        printf("=============================\n");
    }
}

int main() {
    experiment_1();
    experiment_2();
    experiment_3();
    return 0;
}

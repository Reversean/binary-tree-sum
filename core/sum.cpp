#include <omp.h>
#include <cstdio>
#include "tree_node.h"

void sum_tree_sequential(TreeNode *root) {
    double startTime = omp_get_wtime();
    root->SumSequential();
    double endTime = omp_get_wtime();

    printf("[Sequential] Time: %lf\n", endTime - startTime);
}

void sum_tree_pthread(TreeNode *root, int thread_count = omp_get_num_procs()) {
    double startTime = omp_get_wtime();
    root->SumPthread(thread_count);
    double endTime = omp_get_wtime();

    printf("[Pthread] Time: %lf\n", endTime - startTime);
}

void sum_tree_openmp(TreeNode *root, int thread_count = omp_get_num_procs()) {
    double startTime = omp_get_wtime();
    root->SumOpenMP(thread_count);
    double endTime = omp_get_wtime();

    printf("[OpenMP] Time: %lf\n", endTime - startTime);
}

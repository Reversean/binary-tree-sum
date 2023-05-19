#ifndef N_ARY_TREE_SUM_SUM_H
#define N_ARY_TREE_SUM_SUM_H

#include <omp.h>

void sum_tree_sequential(TreeNode *root);

void sum_tree_pthread(TreeNode *root, int thread_count = omp_get_num_procs());

void sum_tree_openmp(TreeNode *root, int thread_count = omp_get_num_procs());

#endif //N_ARY_TREE_SUM_SUM_H

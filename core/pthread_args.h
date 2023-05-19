#ifndef N_ARY_TREE_SUM_PTHREAD_ARGS_H
#define N_ARY_TREE_SUM_PTHREAD_ARGS_H

#include <pthread.h>
#include "tree_node.h"

struct PthreadArgs {
    TreeNode *node;
    int thread_count;
};

#endif //N_ARY_TREE_SUM_PTHREAD_ARGS_H

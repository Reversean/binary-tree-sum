#include "../core/utils.h"
#include "../core/sum.h"

int main() {
    TreeNode *tree = GenerateRandomTree(4);
    sum_tree_openmp(tree);
    tree->PrintTree(true);
    return 0;
}

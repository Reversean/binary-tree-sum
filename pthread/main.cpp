#include "../core/utils.h"
#include "../core/sum.h"

int main() {
    TreeNode *tree = GenerateRandomTree(4);
    sum_tree_pthread(tree);
    tree->PrintTree(true);
    return 0;
}

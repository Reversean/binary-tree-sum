#ifndef N_ARY_TREE_SUM_TREE_NODE_H
#define N_ARY_TREE_SUM_TREE_NODE_H

#include <vector>

class TreeNode {
public:
    explicit TreeNode(int value) : value_(value) {}

    int GetValue();

    double GetChildSum();

    TreeNode *SetLeftNode(int value);

    TreeNode *SetLeftNode(TreeNode *node);

    TreeNode *GetLeftNode();

    TreeNode *SetRightNode(int value);

    TreeNode *SetRightNode(TreeNode *node);

    TreeNode *GetRightNode();

    void SumSequential();

    void SumPthread(int thread_count);

    void SumOpenMP(int thread_count);

    void CleanSum();

    void PrintTree(bool print_child_sum);

private:
    int value_;
    double child_sum_{};
    TreeNode *left_child_{};
    TreeNode *right_child_{};

    static double SumSequentialRoutine(TreeNode *node);

    static void *SumPthreadRoutine(void *args);

    static double SumOpenMPRoutine(TreeNode *node);

    void PrintTree(
        bool print_child_sum, int depth, std::vector<bool> flag, bool is_last);
};

#endif //N_ARY_TREE_SUM_TREE_NODE_H

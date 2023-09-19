#ifndef N_ARY_TREE_SUM_TREE_NODE_H
#define N_ARY_TREE_SUM_TREE_NODE_H

class TreeNode {
public:
    explicit TreeNode(int value) : value_(value) {}

    int GetValue();

    long long GetChildSum();

    TreeNode *SetLeftNode(int value);

    TreeNode *SetLeftNode(TreeNode *node);

    TreeNode *GetLeftNode();

    TreeNode *SetRightNode(int value);

    TreeNode *SetRightNode(TreeNode *node);

    TreeNode *GetRightNode();

private:
    int value_;
    long long child_sum_{};
    TreeNode *left_child_{};
    TreeNode *right_child_{};
};

#endif //N_ARY_TREE_SUM_TREE_NODE_H

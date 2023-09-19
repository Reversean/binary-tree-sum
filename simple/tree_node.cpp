#include "tree_node.h"

int TreeNode::GetValue() {
    return value_;
}

long long TreeNode::GetChildSum() {
    return child_sum_;
}

TreeNode *TreeNode::SetLeftNode(int value) {
    left_child_ = new TreeNode(value);
    return left_child_;
}

TreeNode *TreeNode::SetLeftNode(TreeNode *node) {
    left_child_ = node;
    return left_child_;
}

TreeNode *TreeNode::GetLeftNode() {
    return left_child_;
}

TreeNode *TreeNode::SetRightNode(int value) {
    right_child_ = new TreeNode(value);
    return right_child_;
}

TreeNode *TreeNode::SetRightNode(TreeNode *node) {
    right_child_ = node;
    return right_child_;
}

TreeNode *TreeNode::GetRightNode() {
    return right_child_;
}

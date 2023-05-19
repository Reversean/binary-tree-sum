#include <iostream>
#include <omp.h>
#include <map>
#include "tree_node.h"
#include "pthread_args.h"
#include "utils.h"

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

long long TreeNode::SumSequentialRoutine(TreeNode *node) {
    node->child_sum_ = 0;
    if (node->left_child_ != nullptr) {
        node->child_sum_ += SumSequentialRoutine(node->left_child_);
    }
    if (node->right_child_ != nullptr) {
        node->child_sum_ += SumSequentialRoutine(node->right_child_);
    }
    return node->child_sum_ + node->value_;
}

void TreeNode::SumSequential() {
    SumSequentialRoutine(this);
}

void *TreeNode::SumPthreadRoutine(void *args) {
    auto *pthread_args = (PthreadArgs *) args;
    auto node = pthread_args->node;
    auto thread_count = pthread_args->thread_count;

    if (thread_count <= 1) {
        node->SumSequential();
        return nullptr;
    }

    node->child_sum_ = 0;

    pthread_t threads[2];
    if (node->left_child_ != nullptr) {
        PthreadArgs left_args = {node->left_child_, thread_count / 2};
        pthread_create(&threads[0], nullptr, TreeNode::SumPthreadRoutine, (void *) &left_args);
    }
    if (node->right_child_ != nullptr) {
        PthreadArgs right_args = {node->right_child_, thread_count - thread_count / 2};
        pthread_create(&threads[1], nullptr, TreeNode::SumPthreadRoutine, (void *) &right_args);
    }

    int res;
    if (node->left_child_ != nullptr) {
        pthread_join(threads[0], (void **) &res);
        node->child_sum_ += node->left_child_->child_sum_ + node->left_child_->value_;
    }
    if (node->right_child_ != nullptr) {
        pthread_join(threads[1], (void **) &res);
        node->child_sum_ += node->right_child_->child_sum_ + node->right_child_->value_;
    }

    return nullptr;
}

void TreeNode::SumPthread(int thread_count) {
    PthreadArgs args = {this, thread_count};
    SumPthreadRoutine((void *) &args);
}

long long TreeNode::SumOpenMPRoutine(TreeNode *node) {
    if (omp_get_active_level() >= omp_get_max_active_levels()) {
        return SumSequentialRoutine(node);
    }

    node->child_sum_ = 0;
    int left_sum = 0;
    int right_sum = 0;

#pragma omp parallel sections num_threads(2) default(none) shared(node, left_sum, right_sum)
    {
#pragma omp section
        {
            if (node->left_child_ != nullptr) {
                left_sum = SumOpenMPRoutine(node->left_child_);
            }
        }
#pragma omp section
        {
            if (node->right_child_ != nullptr) {
                right_sum = SumOpenMPRoutine(node->right_child_);
            }
        }
    }
    node->child_sum_ = left_sum + right_sum;
    return node->child_sum_ + node->value_;
}

void TreeNode::SumOpenMP(int thread_count) {
    omp_set_nested(1);
    omp_set_max_active_levels(log2(thread_count));
    SumOpenMPRoutine(this);
}

void TreeNode::CleanSum() {
    child_sum_ = 0;
    if (left_child_ != nullptr) {
        left_child_->CleanSum();
    }
    if (right_child_ != nullptr) {
        right_child_->CleanSum();
    }
}

void TreeNode::PrintTree(
    bool print_child_sum, int depth, std::vector<bool> flag, bool is_last) {
    for (int i = 1; i < depth; i++) {
        if (flag[i]) printf("|    ");
        else printf("     ");
    }

    if (depth > 0) {
        printf("+--- ");
        if (is_last) {
            if (flag.size() < depth) flag.push_back(false);
            else flag[depth] = false;
        }
    }

    if (print_child_sum) {
        printf("%d, %lld\n", value_, child_sum_);
    } else {
        printf("%d\n", value_);
    }

    if (left_child_ != nullptr) {
        int next_depth = depth + 1;
        if (flag.size() < next_depth) flag.push_back(true);
        left_child_->PrintTree(
            print_child_sum, depth + 1, flag, right_child_ == nullptr);
    }
    if (right_child_ != nullptr) {
        int next_depth = depth + 1;
        if (flag.size() < next_depth) flag.push_back(true);
        right_child_->PrintTree(
            print_child_sum, depth + 1, flag, true);
    }
    flag[depth] = true;
}

void TreeNode::PrintTree(bool print_child_sum) {
    std::vector<bool> flag = std::vector<bool>();
    PrintTree(print_child_sum, 0, flag, false);
}

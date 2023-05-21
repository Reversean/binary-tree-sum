#include <random>
#include <functional>
#include "tree_node.h"

const int min_node_value = 1;
const int max_node_value = 100;

TreeNode *GenerateRandomTree(int max_depth) {
    if (max_depth < 1) {
        printf("Invalid tree parameters\n");
        return nullptr;
    }

    std::random_device random_seed;
    std::default_random_engine random_generator(random_seed());
    std::uniform_int_distribution<int> value_generator(min_node_value, max_node_value);

    int node_count = 1;
    int depth = 1;
    auto *root = new TreeNode(value_generator(random_generator));
    std::vector<TreeNode *> current_depth_nodes = std::vector<TreeNode *>{root};
    std::vector<TreeNode *> child_nodes = std::vector<TreeNode *>();

    while (depth < max_depth) {
        for (auto n: current_depth_nodes) {
            TreeNode *left_child = n->SetLeftNode(value_generator(random_generator));
            child_nodes.emplace_back(left_child);
            TreeNode *right_child = n->SetRightNode(value_generator(random_generator));
            child_nodes.emplace_back(right_child);
            node_count += 2;
        }
        depth++;
        current_depth_nodes.swap(child_nodes);
        child_nodes.clear();
    }

    printf("Tree generated\n");
    printf("Total nodes: %d\n", node_count);
    printf("=============================\n");

    return root;
}

int log2(int n) {
    return int(log(n) / log(2));
}

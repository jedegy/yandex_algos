// https://contest.yandex.ru/contest/24809/problems/B/
#ifndef REMOTE_JUDGE
struct Node {
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
    Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};
#endif

#ifdef REMOTE_JUDGE
#include "solution_tree.h"
#endif
#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

bool is_balanced(const Node* root, int& height) {
    if (root == nullptr) {
        height = 0;
        return true;
    }

    int left_subtree_height = 0;
    int right_subtree_height = 0;

    bool left_subtree_balanced = is_balanced(root->left, left_subtree_height);
    bool right_subtree_balanced = is_balanced(root->right, right_subtree_height);

    height = max(left_subtree_height, right_subtree_height) + 1;

    if (!left_subtree_balanced || !right_subtree_balanced) {
        return false;
    }

    return abs(left_subtree_height - right_subtree_height) <= 1;
}

bool Solution(const Node* root) {
    int height = 0;
    return is_balanced(root, height);
}


#ifndef REMOTE_JUDGE
void test() {
    Node node1({1, nullptr, nullptr});
    Node node2({-5, nullptr, nullptr});
    Node node3({3, &node1, &node2});
    Node node4({10, nullptr, nullptr});
    Node node5({2, &node3, &node4});
    assert(Solution(&node5));
}

int main() {
    test();
}
#endif
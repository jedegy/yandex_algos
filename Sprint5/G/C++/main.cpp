// https://contest.yandex.ru/contest/24809/problems/G/
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
#include <climits>

using namespace std;


int find_max_path(const Node* root, int& max_path) {
    if (root == nullptr)
        return 0;

    int left_max = std::max(0, find_max_path(root->left, max_path));
    int right_max = std::max(0, find_max_path(root->right, max_path));

    max_path = std::max(max_path, root->value + left_max + right_max);
    max_path = std::max(max_path, root->value + std::max(left_max, right_max));

    return root->value + std::max(left_max, right_max);
}

int Solution(const Node* root) {
    int max_path = INT_MIN;
    find_max_path(root, max_path);
    return max_path;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({5, nullptr, nullptr});
    Node node2({1, nullptr, nullptr});
    Node node3({-3, &node2, &node1});
    Node node4({2, nullptr, nullptr});
    Node node5({2, &node4, &node3});
    assert(Solution(&node5) == 6);
}

int main() {
    test();
}
#endif
// https://contest.yandex.ru/contest/24809/problems/H/
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

void numeric_paths(const Node* root, int current_number, int& total_sum) {
    if (root == nullptr)
        return;

    current_number = current_number * 10 + root->value;

    if (root->left == nullptr && root->right == nullptr) {
        total_sum += current_number;
        return;
    }

    numeric_paths(root->left, current_number, total_sum);
    numeric_paths(root->right, current_number, total_sum);
}

int Solution(const Node* root) {
    int total_sum = 0;
    numeric_paths(root, 0, total_sum);

    return total_sum;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({2, nullptr, nullptr});
    Node node2({1, nullptr, nullptr});
    Node node3({3, &node1, &node2});
    Node node4({2, nullptr, nullptr});
    Node node5({1, &node4, &node3});
    assert(Solution(&node5) == 275);
}

int main() {
    test();
}
#endif
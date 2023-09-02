// https://contest.yandex.ru/contest/24809/problems/E/
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
#include <limits.h>

using namespace std;


bool is_binary_search_tree(const Node* root, int min, int max) {
    if (root == nullptr) {
        return true;
    }

    if (root->value <= min || root->value >= max) {
        return false;
    }

    return is_binary_search_tree(root->left, min, root->value) && is_binary_search_tree(root->right, root->value, max);
}

bool Solution(const Node* root) {
    return is_binary_search_tree(root, INT_MIN, INT_MAX);
}

#ifndef REMOTE_JUDGE
void test() {
    {
        Node node1({1, nullptr, nullptr});
        Node node2({4, nullptr, nullptr});
        Node node3({3, &node1, &node2});
        Node node4({8, nullptr, nullptr});
        Node node5({5, &node3, &node4});
        assert(Solution(&node5));
    }
    {
        Node node1({1, nullptr, nullptr});
        Node node2({5, nullptr, nullptr});
        Node node3({3, &node1, &node2});
        Node node4({8, nullptr, nullptr});
        Node node5({5, &node3, &node4});
        assert(!Solution(&node5));
    }
}


int main() {
    test();
}
#endif
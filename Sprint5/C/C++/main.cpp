// https://contest.yandex.ru/contest/24809/problems/C/
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


bool is_anagram(const Node* tree1, const Node* tree2) {
    if (tree1 == nullptr && tree2 == nullptr) return true;

    if (tree1 == nullptr || tree2 == nullptr) return false;

    return (tree1->value == tree2->value) &&
            is_anagram(tree1->right, tree2->left) &&
            is_anagram(tree1->left, tree2->right);
}

bool Solution(const Node* root) {
    return is_anagram(root, root);
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({3, nullptr, nullptr});
    Node node2({4, nullptr, nullptr});
    Node node3({4, nullptr, nullptr});
    Node node4({3, nullptr, nullptr});
    Node node5({2, &node1, &node2});
    Node node6({2, &node3, &node4});
    Node node7({1, &node5, &node6});
    assert(Solution(&node7));
}


int main() {
    test();
}
#endif
/*
-- WORKING PRINCIPLE --
This program implements a binary search tree (BST) with an operation to remove a node by its key.
The program ensures that the tree remains a valid BST after the deletion.
The `remove` function searches for the node by its key and then deletes it while maintaining the BST property.
The helper function `find_min` is used to find the minimum key node in a given subtree.

-- PROOF OF CORRECTNESS --
The `remove` function ensures that the tree remains a valid BST in several steps:
1. It recursively searches for the node to be deleted.
2. If the node has zero or one child, it deletes the node and returns the non-null child, if any.
3. If the node has two children, it finds the in-order successor (minimum node in the right subtree), replaces the
 node's key with that of the successor, and then recursively deletes the successor.
By these operations, the BST property is maintained at every step.

-- TIME COMPLEXITY --
The time complexity for the `remove` operation is `O(h)` where `h` is the height of the tree.
This is because in the worst case, we might have to traverse from the root node to a leaf node.

-- SPACE COMPLEXITY --
The space complexity is `O(1)` for the `remove` function as it operates in-place and doesn't use any additional data
 structures.

Link to successful report: https://contest.yandex.ru/contest/24810/run-report/90052891/
*/
#ifndef REMOTE_JUDGE
struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(Node* left, Node* right, int value) : value(value), left(left), right(right) {}
};
#endif
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif
#include <cassert>

Node* find_min(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* remove(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->value) {
        root->left = remove(root->left, key);
    } else if (key > root->value) {
        root->right = remove(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = find_min(root->right);

        root->value = temp->value;

        root->right = remove(root->right, temp->value);
    }

    return root;
}

#ifndef REMOTE_JUDGE
void test() {
    Node* node1 = new Node({nullptr, nullptr, 2});
    Node* node2 = new Node({node1, nullptr, 3});
    Node* node3 = new Node({nullptr, node2, 1});
    Node* node4 = new Node({nullptr, nullptr, 6});
    Node* node5 = new Node({node4, nullptr, 8});
    Node* node6 = new Node({node5, nullptr, 10});
    Node* node7 = new Node({node3, node6, 5});
    Node* newHead = remove(node7, 10);
    assert(newHead->value == 5);
    assert(newHead->right == node5);
    assert(newHead->right->value == 8);
}

int main() {
    test();
}
#endif
// https://contest.yandex.ru/contest/22779/problems/C/
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#ifndef REMOTE_JUDGE
#include <cassert>
#include <string>

struct Node {
    std::string value;
    Node* next;
    Node(const std::string &value, Node* next) : value(value), next(next) {

    }
};
#endif


Node* solution(Node* head, int idx) {
    if (!idx) {
        return head->next;
    }

    Node* cur = head;
    Node* prev = nullptr;
    while (cur != nullptr) {
        if (!idx) {
            prev->next = cur->next;
            break;
        }
        prev = cur;
        cur = cur->next;
        idx--;
    }

    return head;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node3("node3", nullptr);
    Node node2("node2", &node3);
    Node node1("node1", &node2);
    Node node0("node0", &node1);
    Node* new_head = solution(&node0, 3);
    assert(new_head == &node0);
    assert(new_head->next == &node1);
    assert(new_head->next->next == &node2);
    assert(new_head->next->next->next == nullptr);
    // result is : node0 -> node2 -> node3
}

int main() {
    test();
}
#endif
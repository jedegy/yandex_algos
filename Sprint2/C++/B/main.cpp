// https://contest.yandex.ru/contest/22779/problems/B/
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif

#include <iostream>

#ifndef REMOTE_JUDGE

#include <string>

struct Node {
    std::string value;
    Node* next;
    Node(const std::string &value, Node* next) : value(value), next(next) {}
};

#endif


void solution(Node* head) {
    while (head->next != nullptr) {
        std::cout<<head->value<<std::endl;
        head = head->next;
    }
    std::cout<<head->value<<std::endl;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node3("node3", nullptr);
    Node node2("node2", &node3);
    Node node1("node1", &node2);
    Node node0("node0", &node1);
    solution(&node0);
    /*
    Output is:
    node0
    node1
    node2
    node3
    */
}

int main() {
    test();
}
#endif
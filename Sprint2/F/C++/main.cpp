// https://contest.yandex.ru/contest/22779/problems/F/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <climits>

class Stack {
private:
    class Node {
    public:
        int value;
        Node *next;

        Node(int value) : value(value), next(nullptr) {}
    };

    Node *head;
    int max_value;
public:
    Stack() : head(nullptr), max_value(-1 * INT_MAX) {};

    ~Stack() {
        while (!empty()) {
            pop();
        }
    }

    bool empty() const {
        return head == nullptr;
    }

    int get_max() {
        return max_value;
    }

    void push(int value) {
        if (max_value <= value) {
            max_value = value;
        }
        Node *new_head = new Node(value);
        new_head->next = head;
        head = new_head;
    }

    int pop() {
        if (empty()) {
            return -1;
        }
        if (head->value == max_value) {
            Node *curr = head->next;
            max_value = -1 * INT_MAX;
            while (curr != nullptr) {
                if (max_value <= curr->value) {
                    max_value = curr->value;
                }
                curr = curr->next;
            }
        }

        head = head->next;

        return 0;
    }
};

int main() {
    int n;
    Stack stack;
    std::string command;
    std::cin >> n;

    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(std::cin, command);
        std::vector<std::string> parts;
        std::istringstream iss(command);
        std::string part;
        while (iss >> part) {
            parts.push_back(part);
        }

        if (parts[0] == "push") {
            int number = stoi(parts[1]);
            stack.push(number);
        } else if (parts[0] == "pop") {
            if (stack.pop()) {
                std::cout << "error" << std::endl;
            }
        } else if (parts[0] == "get_max") {
            if (stack.empty()) {
                std::cout << "None" << std::endl;
            } else {
                std::cout << stack.get_max() << std::endl;
            }
        }
    }
}
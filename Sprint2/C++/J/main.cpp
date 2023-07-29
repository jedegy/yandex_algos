// https://contest.yandex.ru/contest/22779/problems/J/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Dec {
    class Node {
    public:
        int value;
        Node* next;
        explicit Node(int value):value(value), next(nullptr) {};
    };

    int curr_size = 0;
    Node* head{};
    Node* tail = head;

public:
    ~Dec() {
        while (!is_empty()) {
            pop();
        }
    }

    void push(int x) {
        Node *node = new Node(x);
        if (is_empty()) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        curr_size++;
    }

    bool is_empty() {
        return head == nullptr;
    }

    std::string pop() {
        if (!is_empty()) {
            Node* temp = head;
            head = head->next;
            curr_size--;
            int value = temp->value;
            delete temp;

            return std::to_string(value);
        } else {
            return "error";
        }
    }

    int size() const {
        return curr_size;
    }
};

int main() {
    int n;
    std::string command;
    std::cin >> n;

    Dec queue = Dec();

    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(std::cin, command);
        std::vector<std::string> parts;
        std::istringstream iss(command);
        std::string part;
        while (iss >> part) {
            parts.push_back(part);
        }

        if (parts[0] == "put") {
            int number = stoi(parts[1]);
            queue.push(number);
        } else if (parts[0] == "get") {
            std::cout << queue.pop() << std::endl;
        } else if (parts[0] == "size") {
            std::cout << queue.size() << std::endl;
        }
    }
}
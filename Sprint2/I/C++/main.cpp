// https://contest.yandex.ru/contest/22779/problems/I/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Dec {
    class Node {
    public:
        int value;
        Node *next;

        explicit Node(int value) : value(value), next(nullptr) {};
    };

    int max_size;
    int curr_size;
    Node *head{};
    Node *tail = head;

public:
    explicit Dec(int max_size) : max_size(max_size), curr_size(0) {};

    ~Dec() {
        while (!is_empty()) {
            pop();
        }
    }

    int push(int x) {
        if (curr_size < max_size) {
            Node *node = new Node(x);
            if (is_empty()) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
            curr_size++;
            return 0;
        } else {
            return -1;
        }
    }

    bool is_empty() {
        return head == nullptr;
    }

    std::string pop() {
        if (!is_empty()) {
            Node *temp = head;
            head = head->next;
            curr_size--;
            int value = temp->value;
            delete temp;

            return std::to_string(value);
        } else {
            return "None";
        }
    }

    std::string peek() {
        if (!is_empty()) {
            int value = head->value;
            return std::to_string(value);
        } else {
            return "None";
        }
    }

    int size() const {
        return curr_size;
    }
};

int main() {
    int n, m;
    std::string command;
    std::cin >> n;
    std::cin >> m;

    Dec queue = Dec(m);

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
            if (queue.push(number)) {
                std::cout << "error" << std::endl;
            }
        } else if (parts[0] == "pop") {
            std::cout << queue.pop() << std::endl;
        } else if (parts[0] == "peek") {
            std::cout << queue.peek() << std::endl;
        } else if (parts[0] == "size") {
            std::cout << queue.size() << std::endl;
        }
    }
}
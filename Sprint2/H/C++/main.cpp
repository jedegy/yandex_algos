// https://contest.yandex.ru/contest/22779/problems/H/
#include <iostream>
#include <string>
#include <stack>

bool is_correct_bracket_seq(std::string& seq) {
    std::stack<char> brackets;

    for (char elem: seq) {
        if (elem == '}' || elem == ']' || elem == ')') {
            if (brackets.empty())
                return false;
            if (elem == '}' && brackets.top() != '{')
                return false;
            if (elem == ')' && brackets.top() != '(')
                return false;
            if (elem == ']' && brackets.top() != '[')
                return false;
            brackets.pop();
        } else {
            brackets.push(elem);
        }
    }

    if (brackets.empty())
        return true;

    return false;
}

int main() {
    std::string seq;
    std::cin >> seq;

    if (is_correct_bracket_seq(seq)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}

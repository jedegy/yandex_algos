// https://contest.yandex.ru/contest/23638/problems/B/
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<char>> phone_keypad{
        {},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
};

void print_combinations(std::string input_keys, const std::string& combination, int index) {
    if (index == input_keys.size()) {
        std::cout << combination << " ";
        return;
    }

    for (char letter: phone_keypad[input_keys[index] - '0']) {
        print_combinations(input_keys, combination + letter, index + 1);
    }
}


int main() {
    std::string input_keys;
    std::cin >> input_keys;

    print_combinations(input_keys, "", 0);
    std::cout << std::endl;

    return 0;
}
// https://contest.yandex.ru/contest/23638/problems/A/
#include <iostream>
#include <string>

void gen_bracket_sequences(int open, int close, const std::string& prefix) {
    if (!open && !close) {
        std::cout << prefix << std::endl;
    }
    if (open) {
        gen_bracket_sequences(open - 1, close + 1, prefix + "(");
    }
    if (close) {
        gen_bracket_sequences(open, close - 1, prefix + ")");
    }
}

int main() {
    int n;
    std::cin >> n;
    gen_bracket_sequences(n, 0, "");

    return 0;
}
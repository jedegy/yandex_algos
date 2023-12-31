// https://contest.yandex.ru/contest/22449/problems/B/
#include <iostream>

bool hasSameParity(int num1, int num2, int num3) {
    bool num1_is_even = num1 % 2 == 0;
    bool num2_is_even = num2 % 2 == 0;
    bool num3_is_even = num3 % 2 == 0;

    if ((num1_is_even && num2_is_even && num3_is_even) || (!num1_is_even && !num2_is_even && !num3_is_even)) {
        return true;
    }

    return false;
}

int main() {
    int num1, num2, num3;

    std::cin >> num1 >> num2 >> num3;

    if (hasSameParity(num1, num2, num3)) {
        std::cout << "WIN" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }

    return 0;
}
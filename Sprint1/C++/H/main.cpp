// https://contest.yandex.ru/contest/22449/problems/H/
#include <iostream>

std::string bin_summ(std::string& num1, std::string& num2) {
    std::string result;

    int carry = 0;
    int i = (int) num1.length() - 1;
    int j = (int) num2.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) {
            sum += num1[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += num2[j] - '0';
            j--;
        }

        carry = sum / 2;
        sum = sum % 2;

        result.push_back('0' + sum);
    }
    std::string result_rev;

    for (int k = (int) result.length() - 1; k >= 0; k--) {
        result_rev.push_back(result[k]);
    }

    return result_rev;
}

int main() {
    std::string num1, num2;

    std::cin>> num1;
    std::cin>> num2;

    std::cout<<bin_summ(num1, num2)<<std::endl;
    return 0;
}

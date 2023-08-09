// https://contest.yandex.ru/contest/22449/problems/K/
#include <iostream>
#include <vector>

std::vector<short> to_list_form(unsigned int n) {
    std::vector<short> result;

    while (n != 0) {
        result.push_back((short) (n % 10));
        n /= 10;
    }

    std::vector<short> result_rev;

    for (int i = (int) result.size() - 1; i >= 0; i--) {
        result_rev.push_back(result[i]);
    }

    return result_rev;
}

std::vector<int> add_list_form(std::vector<short>& num1, std::vector<short>& num2) {
    std::vector<int> result;

    int carry = 0;
    int i = (int) num1.size() - 1;
    int j = (int) num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) {
            sum += num1[i];
            i--;
        }
        if (j >= 0) {
            sum += num2[j];
            j--;
        }

        carry = sum / 10;
        sum = sum % 10;

        result.push_back(sum);
    }
    std::vector<int> result_rev;

    for (int k = (int) result.size() - 1; k >= 0; k--) {
        result_rev.push_back(result[k]);
    }

    return result_rev;
}

int main() {
    unsigned int n;
    unsigned int k;
    std::vector<short> x;

    std::cin >> n;

    for (unsigned int i = 0; i < n; i++) {
        short value;
        std::cin >> value;
        x.push_back(value);
    }

    std::cin >> k;
    std::vector<short> k_form = to_list_form(k);
    std::vector<int> summ = add_list_form(x, k_form);

    for (int digit: summ) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    return 0;
}

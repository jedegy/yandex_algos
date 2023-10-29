// https://contest.yandex.ru/contest/26131/problems/C/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::vector<int> alphabet(26, 0);

    std::cin >> s;

    for (char ch: s) {
        alphabet[ch - 'a'] += 1;
    }

    int center_l = 0, center_r = 0;
    std::string result;

    for (int i = 0; i < 26; ++i) {
        if (alphabet[i] != 0) {
            if (center_l == center_r) {
                result.insert(center_l, alphabet[i], char(i + 'a'));
                center_l += alphabet[i] / 2;

                if (alphabet[i] % 2 == 0) {
                    center_r = center_l;
                } else {
                    center_r = center_l + 1;
                }
            } else {
                if (alphabet[i] / 2 > 0) {
                    result.insert(center_l, alphabet[i] / 2, char(i + 'a'));
                    result.insert(center_r + alphabet[i] / 2, alphabet[i] / 2, char(i + 'a'));

                    center_l = result.length() / 2;
                    center_r = center_l + 1;
                }
            }
        }
    }

    std::cout << result << std::endl;
}
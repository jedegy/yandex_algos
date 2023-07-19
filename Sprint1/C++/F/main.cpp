// https://contest.yandex.ru/contest/22449/problems/F/
#include <iostream>
#include <string>

bool is_palindrome(std::string& phrase) {
    unsigned int left = 0;
    unsigned int right = phrase.length() - 1;

    while (left < right) {
        while (left < right && !isalnum(phrase[left])) {
            left++;
        }
        while (left < right && !isalnum(phrase[right])) {
            right--;
        }
        if (tolower(phrase[left]) != tolower(phrase[right])) {
            return false;
        }
        left++;

        if (right > 0) {
            right--;
        }
    }

    return true;
}

int main() {
    std::string phrase;
    std::getline(std::cin, phrase);

    if (is_palindrome(phrase)) {
        std::cout<<"True"<<std::endl;
    } else {
        std::cout<<"False"<<std::endl;
    }

    return 0;
}

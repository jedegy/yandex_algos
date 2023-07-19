// https://contest.yandex.ru/contest/22449/problems/G/
#include <iostream>
#include <string>

std::string dec_to_bin(int n) {
    if (n == 0) {
        return "0";
    } else if (n == 1) {
        return "1";
    } else {
        return dec_to_bin(n >> 1) + std::to_string(n % 2);
    }
}

int main() {
    int n;
    std::cin>>n;
    std::cout<<dec_to_bin(n)<<std::endl;
}
/*
-- WORKING PRINCIPLE --
This program finds the longest common prefix of unpacked strings, where the input strings are given in a compressed format.

-- PROOF OF CORRECTNESS --
The algorithm's correctness is ensured by:
 1. Unpacking strings using a recursive approach, which correctly unfolds the compressed sequences.
 2.Sequentially comparing characters in the strings to determine the common prefix.

-- TIME COMPLEXITY --
1. Unpacking: In the worst case, where each character of the string multiplies the length of the string many times over (for example, "2[a2[b2[c...]]]"),
 the complexity of unpacking can reach O(k^d), where k is the length of the string after unpacking and d is the maximum depth of nesting.
2. Finding the largest common prefix between n strings with a maximum length of k will take O(n * k).
 The overall time complexity will be O(n * k^d + n * k).

-- SPACE COMPLEXITY --
1. The current common prefix can occupy O(k).
2. Recursive calls: The unpack function can recursively call itself depending on the nesting depth of the string.
 In the worst case, this may require O(d) additional stack space.
 The program's overall space complexity is O(k + d).

Link to successful report: https://contest.yandex.ru/contest/26133/run-report/95128626/
*/
#include <iostream>
#include <string>
#include <vector>

// Function unpacks the packed input string
std::string unpack(const std::string &s) {
    std::string result;
    int i = 0;
    while (i < s.size()) {
        if (isdigit(s[i])) {
            int count = s[i] - '0';
            int start = i + 2;
            int end = start;
            int balance = 1;
            while (balance != 0) {
                if (s[end] == '[') {
                    balance++;
                } else if (s[end] == ']') {
                    balance--;
                }
                end++;
            }
            std::string sub = unpack(s.substr(start, end - start - 1));
            for (int j = 0; j < count; j++) {
                result += sub;
            }
            i = end;
        } else {
            result += s[i];
            i++;
        }
    }
    return result;
}

// Function updates the common greatest prefix
void update_prefix(std::string &prefix, const std::string &s) {
    int j = 0;
    while (j < prefix.size() && j < s.size() && prefix[j] == s[j]) {
        j++;
    }
    prefix = prefix.substr(0, j);
}

int main() {
    int n;
    std::cin >> n;

    std::string prefix;
    if (n > 0) {
        std::string s;
        std::cin >> s;
        prefix = unpack(s);
    }

    for (int i = 1; i < n; i++) {
        std::string s;
        std::cin >> s;
        update_prefix(prefix, unpack(s));
    }

    std::cout << prefix << std::endl;
    return 0;
}

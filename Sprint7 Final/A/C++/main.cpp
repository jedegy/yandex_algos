/*
-- WORKING PRINCIPLE --
This program calculates the Levenshtein distance between two input strings.
The Levenshtein distance between two strings is defined as the minimum number of atomic changes (i.e., insertions,
deletions, or replacements) required to transform one string into another.

-- PROOF OF CORRECTNESS --
The program accurately calculates the Levenshtein distance between two strings using dynamic programming:

1. The program creates two vectors of size m + 1: `prev` and `current`. The `prev` vector stores the distance for the previous iteration
of string `s`, while `current` is used for the current iteration.
2. Base cases: the `prev` vector is filled with values from 0 to m, as the distance between an empty string and a string of length m is m.
3. For each character from string `s`, the program updates the `current` vector based on values from `prev` and `current`, using
the recursive relation:
   - Deletion (prev[j] + 1)
   - Insertion (current[j - 1] + 1)
   - Replacement (prev[j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1))

The Levenshtein distance between strings `s` and `t` is found in the last element of the prev vector after the main loop completes.

-- TIME COMPLEXITY --
The time complexity of the algorithm is O(n * m), where `n` is the length of string `s`, and `m` is the length of string `t`.

-- SPACE COMPLEXITY --
The space complexity of the program is O(min(n, m)), where `n` is the length of string `s`, and `m` is the length of string `t`.

Link to successful report: https://contest.yandex.ru/contest/25597/run-report/94067760/
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Function to find levenshtein distance between two input strings.
int levenshtein_distance(const std::string &s, const std::string &t) {
    int n = s.length();
    int m = t.length();

    if(n < m) {
        return levenshtein_distance(t, s);
    }

    std::vector<int> prev(m + 1);
    std::vector<int> current(m + 1);

    // Initialize base cases
    for (int i = 0; i <= m; i++) {
        prev[i] = i;
    }

    // Calculate levenshtein distance
    for (int i = 1; i <= n; i++) {
        current[0] = i;
        for (int j = 1; j <= m; j++) {
            current[j] = std::min({prev[j] + 1, current[j - 1] + 1, prev[j - 1] + ((s[i - 1] == t[j - 1]) ? 0 : 1)});
        }
        std::swap(prev, current);
    }

    return prev[m];
}

int main() {
    std::string s, t;
    std::cin >> s >> t;
    std::cout << levenshtein_distance(s, t) << std::endl;
    return 0;
}

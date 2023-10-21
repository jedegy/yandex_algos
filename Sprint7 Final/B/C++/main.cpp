/*
-- WORKING PRINCIPLE --
This program determines if it's possible to split the total points earned in `n` matches into two equal halves.

-- PROOF OF CORRECTNESS --
The program accurately determines the possibility of splitting the points into two subsets of equal sum using dynamic programming:

1. Calculate the total sum of points during data input.
2. If the total sum is odd, then splitting is impossible.
3. Create two one-dimensional arrays `prev` and `current`, where `prev[j]` is true if there exists a subset of points whose sum equals j.
4. Base cases: `prev[0]` is true because a sum of 0 can be achieved with an empty subset.
5. Use a recursive relation to update the prev and current arrays, either including or excluding the current score.
6. If `prev[sum/2]` is true, splitting is possible. Otherwise, it's not.

-- TIME COMPLEXITY --
The time complexity of the algorithm is O(n * sum/2), where `n` is the number of games, and `sum` is the total number of points.
In the worst case, this is O(n^2), when the points in each game are close to 300.

-- SPACE COMPLEXITY --
The space complexity of the program is O(sum/2).

Link to successful report: https://contest.yandex.ru/contest/25597/run-report/94067987/
*/

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> scores(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> scores[i];
        sum += scores[i];
    }

    if (sum % 2 != 0) {
        std::cout << "False" << std::endl;
        return 0;
    }

    std::vector<bool> prev(sum / 2 + 1, false);
    std::vector<bool> current(sum / 2 + 1, false);

    prev[0] = true;

    for (int i = 1; i <= n; i++) {
        current[0] = true;
        for (int j = 1; j <= sum / 2; j++) {
            if (j >= scores[i - 1]) {
                current[j] = prev[j] || prev[j - scores[i - 1]];
            } else {
                current[j] = prev[j];
            }
        }
        std::swap(prev, current);
    }

    if (prev[sum / 2]) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
}

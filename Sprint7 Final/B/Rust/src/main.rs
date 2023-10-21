/*
-- WORKING PRINCIPLE --
This program determines whether the total points earned from `n` table tennis matches can be split into two equal halves.
 The logic is based on the classic subset sum problem and aims to check if there's a subset of the given scores whose sum
 is half of the total points. If such a subset exists, it implies the points can be split into two equal halves.

-- PROOF OF CORRECTNESS --
The program accurately computes the possibility of partitioning the scores into two subsets of equal sum using dynamic programming:

1. Compute the total sum of the points.
2. If the total sum is odd, then partitioning is not possible.
3. Initialize a DP table `dp[i][j]` where `dp[i][j]` is true if there's a subset of the first `i` scores that sum up to `j`.
4. Fill in the base cases: for every `i`, `dp[i][0]` is true because a sum of 0 can be achieved with an empty subset.
5. Use the recurrence relation to fill the DP table by either including the current score or excluding it.
6. If `dp[n][sum/2]` is true, partitioning is possible. Otherwise, it's not.

-- TIME COMPLEXITY --
The time complexity of the algorithm is O(n * sum/2), where `n` is the number of games and `sum` is the total points
 scored. This can be approximated as O(n^2) in the worst-case scenario when each game scores are close to 300.

-- SPACE COMPLEXITY --
The space complexity of the program is O(n * sum/2) due to the storage required for the DP table. This can also be
 approximated as O(n^2) for the given constraints.

Link to successful report: https://contest.yandex.ru/contest/25597/run-report/94007370/
*/

use std::io::{self, BufRead};

fn main() {
    let mut lines = io::stdin().lock().lines();
    let n = lines.next().unwrap().unwrap().parse::<usize>().unwrap();
    let mut sum = 0;
    let scores = lines
        .next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|x| {
            let score = x.parse::<usize>().unwrap();
            sum += score;
            score
        })
        .collect::<Vec<usize>>();

    if sum % 2 != 0 {
        println!("False");
        return;
    }

    let mut dp = vec![vec![false; sum / 2 + 1]; n + 1];

    for i in 0..=n {
        dp[i][0] = true;
    }

    for i in 1..=n {
        for j in 1..=sum / 2 {
            if j >= scores[i - 1] {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - scores[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    if dp[n][sum / 2] {
        println!("True");
    } else {
        println!("False");
    }
}

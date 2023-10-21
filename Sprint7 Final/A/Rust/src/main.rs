/*
-- WORKING PRINCIPLE --
This program computes the Levenshtein distance (also known as the edit distance) between two input strings. The Levenshtein
 distance between two strings is defined as the minimum number of edits (i.e., insertions, deletions, or substitutions)
 required to transform one string into another.

-- PROOF OF CORRECTNESS --
The program correctly computes the Levenshtein distance between two strings using dynamic programming:

1. Represents the problem as a table where `dp[i][j]` stores the distance between the first `i` characters of string `s`
 and the first `j` characters of string `t`.
2. Uses base cases: the distance between an empty string and a string of length `j` is `j` and the distance between a
 string of length `i` and an empty string is `i`.
3. Fills in the table using the recurrence relation which takes into consideration:
   - Deletion (distance[i-1][j] + 1)
   - Insertion (distance[i][j-1] + 1)
   - Substitution (distance[i-1][j-1] + (s[i-1] == t[j-1] ? 0 : 1))

The final value at `dp[n][m]` gives the Levenshtein distance between strings `s` and `t`.

-- TIME COMPLEXITY --
The time complexity of the algorithm is O(n * m), where `n` is the length of string `s` and `m` is the length of string `t`.

-- SPACE COMPLEXITY --
The space complexity of the program is O(n * m) due to the storage required for the `dp` table to compute the distances.

Link to successful report: https://contest.yandex.ru/contest/25597/run-report/94000460/
*/

use std::io::{self, BufRead};

fn levenshtein_distance(s: &str, t: &str) -> u64 {
    let n = s.len();
    let m = t.len();

    let mut dp = vec![vec![0u64; m + 1]; n + 1];
    for i in 0..=n {
        dp[i][0] = i as u64;
    }
    for i in 0..=m {
        dp[0][i] = i as u64;
    }

    for i in 1..=n {
        for j in 1..=m {
            dp[i][j] = std::cmp::min(
                std::cmp::min(dp[i - 1][j] + 1, dp[i][j - 1] + 1),
                dp[i - 1][j - 1] + (s.as_bytes()[i - 1] != t.as_bytes()[j - 1]) as u64,
            );
        }
    }

    dp[n][m]
}

fn main() {
    let mut lines = io::stdin().lock().lines();

    let s = lines.next().unwrap().unwrap();
    let t = lines.next().unwrap().unwrap();

    println!("{}", levenshtein_distance(&s, &t));
}

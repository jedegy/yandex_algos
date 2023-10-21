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

use std::io::{self, BufRead};

fn levenshtein_distance(s: &str, t: &str) -> usize {
    let n = s.len();
    let m = t.len();

    if n < m {
        return levenshtein_distance(t, s);
    }

    let mut prev = vec![0; m + 1];
    let mut current = vec![0; m + 1];
    for j in 0..=m {
        prev[j] = j;
    }

    for i in 1..=n {
        current[0] = i;
        for j in 1..=m {
            current[j] = std::cmp::min(
                std::cmp::min(current[j - 1] + 1, prev[j] + 1),
                prev[j - 1] + (s.as_bytes()[i - 1] != t.as_bytes()[j - 1]) as usize,
            );
        }
        std::mem::swap(&mut prev, &mut current);
    }

    prev[m]
}

fn main() {
    let mut lines = io::stdin().lock().lines();

    let s = lines.next().unwrap().unwrap();
    let t = lines.next().unwrap().unwrap();

    println!("{}", levenshtein_distance(&s, &t));
}

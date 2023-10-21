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

    let mut prev = vec![false; sum / 2 + 1];
    let mut current = vec![false; sum / 2 + 1];

    prev[0] = true;

    for i in 1..=n {
        current[0] = true;
        for j in 1..=sum / 2 {
            current[j] = if j >= scores[i - 1] {
                prev[j] || prev[j - scores[i - 1]]
            } else {
                prev[j]
            };
        }
        std::mem::swap(&mut prev, &mut current);
    }

    if prev[sum / 2] {
        println!("True");
    } else {
        println!("False");
    }
}

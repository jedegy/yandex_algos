// https://contest.yandex.ru/contest/25596/problems/I/

fn main() {
    let mut lines = std::io::stdin().lines();
    let n_m = lines
        .next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|x| x.parse::<usize>().unwrap())
        .collect::<Vec<usize>>();
    let n = n_m[0];
    let m = n_m[1];

    let mut field = vec![Vec::new(); n];
    let mut dp = vec![vec![0; m]; n];

    for row in field.iter_mut() {
        let line = lines.next().unwrap().unwrap();
        for ch in line.chars() {
            row.push(ch.to_digit(10).unwrap());
        }
    }

    dp[n - 1][0] = field[n - 1][0];

    for j in 1..m {
        dp[n - 1][j] = dp[n - 1][j - 1] + field[n - 1][j];
    }

    for i in (0..(n - 1)).rev() {
        dp[i][0] = dp[i + 1][0] + field[i][0];
    }

    for i in (0..(n - 1)).rev() {
        for j in 1..m {
            dp[i][j] = field[i][j] + std::cmp::max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    println!("{}", dp[0][m - 1]);

    let mut path = String::new();
    let mut i = 0;
    let mut j = m - 1;
    while i < n - 1 || j > 0 {
        let mi = if i == n - 1 { -1 } else { dp[i + 1][j] as i32 };
        let mj = if j == 0 { -1 } else { dp[i][j - 1] as i32 };
        if mi > mj {
            path += "U";
            if i != n - 1 {
                i += 1;
            }
        } else {
            path += "R";
            j = j.saturating_sub(1);
        }
    }

    println!("{}", path.chars().rev().collect::<String>());
}

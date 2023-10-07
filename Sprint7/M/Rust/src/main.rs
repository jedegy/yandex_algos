// https://contest.yandex.ru/contest/25596/problems/M/

fn main() {
    let mut lines = std::io::stdin().lines();
    let line = lines.next().unwrap().unwrap();
    let mut n_m = line.split_whitespace();
    let n: usize = n_m.next().unwrap().parse::<usize>().unwrap();
    let m: usize = n_m.next().unwrap().parse::<usize>().unwrap();

    let mut weights = vec![0; n + 1];
    let mut values = vec![0; n + 1];

    for i in 1..=n {
        let line = lines.next().unwrap().unwrap();
        let mut parts = line.split_whitespace();
        weights[i] = parts.next().unwrap().parse::<usize>().unwrap();
        values[i] = parts.next().unwrap().parse::<usize>().unwrap();
    }

    let mut dp = vec![vec![0; m + 1]; n + 1];

    for i in 1..=n {
        for j in 0..=m {
            dp[i][j] = dp[i - 1][j];
            if j >= weights[i] {
                dp[i][j] = dp[i][j].max(dp[i - 1][j - weights[i]] + values[i]);
            }
        }
    }

    let mut result = Vec::new();
    let mut weight = m;

    for i in (1..=n).rev() {
        if dp[i][weight] != dp[i - 1][weight] {
            result.push(i);
            weight -= weights[i];
        }
    }

    println!("{}", result.len());
    for &item in result.iter().rev() {
        print!("{} ", item);
    }
}

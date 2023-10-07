// https://contest.yandex.ru/contest/25596/problems/L/

fn main() {
    let mut lines = std::io::stdin().lines();
    let n_m = lines
        .next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|x| x.parse::<usize>().unwrap())
        .collect::<Vec<usize>>();
    let (n, m) = (n_m[0], n_m[1]);

    let weights = lines
        .next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|x| x.parse::<usize>().unwrap())
        .collect::<Vec<usize>>();

    let mut dp = vec![0; m + 1];

    for i in 0..n {
        for j in (weights[i]..=m).rev() {
            dp[j] = std::cmp::max(dp[j], dp[j - weights[i]] + weights[i]);
        }
    }

    println!("{}", dp[m]);
}

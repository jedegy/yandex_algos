// https://contest.yandex.ru/contest/25596/problems/E/

const DP_MAX: usize = 100_000;

fn main() {
    let mut lines = std::io::stdin().lines();
    let x = lines.next().unwrap().unwrap().parse::<usize>().unwrap();
    let _k = lines.next().unwrap().unwrap().parse::<usize>().unwrap();

    let denominations = lines
        .next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|x| x.parse::<usize>().unwrap())
        .collect::<Vec<usize>>();

    let mut dp = vec![DP_MAX; x + 1];
    dp[0] = 0;

    for i in 1..(x + 1) {
        for d in denominations.iter() {
            if i as i64 - *d as i64 >= 0 {
                dp[i] = std::cmp::min(dp[i], dp[i - *d] + 1);
            }
        }
    }

    if dp[x] == DP_MAX {
        println!("-1");
    } else {
        println!("{}", dp[x]);
    }
}

// https://contest.yandex.ru/contest/25596/problems/G/

fn main() {
    let mut lines = std::io::stdin().lines();
    let m = lines.next().unwrap().unwrap().parse::<usize>().unwrap();
    let n = lines.next().unwrap().unwrap().parse::<usize>().unwrap();

    let coins = lines
        .next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|x| x.parse::<usize>().unwrap())
        .collect::<Vec<usize>>();

    let mut dp = vec![0; m + 1];
    dp[0] = 1;

    for coin in coins {
        for i in coin..(m + 1) {
            dp[i] += dp[i - coin];
        }
    }

    println!("{}", dp[m]);
}

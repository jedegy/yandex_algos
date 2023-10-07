// https://contest.yandex.ru/contest/25596/problems/J/

fn main() {
    let mut lines = std::io::stdin().lines();
    let n = lines.next().unwrap().unwrap().parse::<usize>().unwrap();
    let arr = lines
        .next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|x| x.parse::<usize>().unwrap())
        .collect::<Vec<usize>>();

    let mut dp = vec![1; n];
    let mut prev = vec![-1; n];

    let mut max_len = 1;
    let mut last_index = 0;

    for i in 1..n {
        for j in 0..i {
            if arr[j] < arr[i] && dp[i] < dp[j] + 1 {
                dp[i] = dp[j] + 1;
                prev[i] = j as isize;
            }
        }
        if dp[i] > max_len {
            max_len = dp[i];
            last_index = i;
        }
    }

    println!("{}", max_len);

    let mut result = Vec::new();
    while last_index as isize != -1 {
        result.push(last_index + 1);
        last_index = prev[last_index] as usize;
    }

    for i in result.iter().rev() {
        print!("{} ", i);
    }
}

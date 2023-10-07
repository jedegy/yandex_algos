// https://contest.yandex.ru/contest/25596/problems/A/
fn main() {
    let mut lines = std::io::stdin().lines();
    let n = lines.next().unwrap().unwrap().parse::<usize>().unwrap();

    let prices = lines
        .next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|x| x.parse::<usize>().unwrap())
        .collect::<Vec<usize>>();

    if n <= 1 {
        println!("0");
        return;
    }

    let mut max_profit = 0;

    for i in 1..n {
        if prices[i] > prices[i - 1] {
            max_profit += prices[i] - prices[i - 1];
        }
    }

    println!("{}", max_profit);
}

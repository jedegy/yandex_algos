// https://contest.yandex.ru/contest/25596/problems/F/

fn main() {
    let mut lines = std::io::stdin().lines();
    let n_k = lines
        .next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|x| x.parse::<usize>().unwrap())
        .collect::<Vec<usize>>();

    let n = n_k[0];
    let k = n_k[1];

    let mut ways = vec![0; n + 1];
    ways[1] = 1;

    for i in 2..(n + 1) {
        let mut j = 1;
        while j <= k && j <= i {
            ways[i] = (ways[i] + ways[i - j]) % usize::MAX;
            j += 1;
        }
    }

    println!("{}", ways[n]);
}

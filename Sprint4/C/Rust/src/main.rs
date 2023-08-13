// https://contest.yandex.ru/contest/23991/problems/C/
use std::io::BufRead;

struct PrefixHashes {
    m: i64,
    hashes: Vec<i64>,
    powers: Vec<i64>,
}

impl PrefixHashes {
    fn new(a: i64, m: i64, s: String) -> Self {
        let mut hashes = Vec::with_capacity(s.len() + 1);
        let mut powers = Vec::with_capacity(s.len() + 1);

        powers.push(1i64);
        hashes.push(0i64);
        for i in 1..s.len() + 1 {
            powers.push((powers[i - 1] * a) % m);
            hashes.push((hashes[i - 1] * a + s.as_bytes()[i - 1] as i64) % m);
        }

        Self { m, hashes, powers }
    }

    fn substring_poly_hash(&self, l: usize, r: usize) -> i64 {
        if l == 1 {
            return self.hashes[r];
        }

        let mut result =
            ((self.hashes[r] - self.hashes[l - 1]) * self.powers[r - l + 1] + self.m) % self.m;

        if result < 0 {
            let abs_result = i64::abs(result);
            if abs_result % self.m != 0 {
                result += (abs_result / self.m + 1) * self.m;
                result %= self.m;
            } else {
                result = 0;
            }
        }

        result
    }
}

fn main() {
    let stdin = std::io::stdin();
    let mut lines = stdin.lock().lines();

    let a: i64 = lines.next().unwrap().unwrap().parse().unwrap();
    let m: i64 = lines.next().unwrap().unwrap().parse().unwrap();

    let s = lines.next().unwrap().unwrap();

    let prefix_hashes = PrefixHashes::new(a, m, s);

    let t: usize = lines.next().unwrap().unwrap().parse().unwrap();
    for _ in 0..t {
        let line = lines.next().unwrap().unwrap();
        let parts = line
            .split_whitespace()
            .map(|x| x.parse::<usize>().unwrap())
            .collect::<Vec<usize>>();
        let l = parts[0];
        let r = parts[1];
        println!("{}", prefix_hashes.substring_poly_hash(l, r));
    }
}

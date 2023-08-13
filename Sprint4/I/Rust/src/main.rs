// https://contest.yandex.ru/contest/23991/problems/I/

const BASE1: i64 = 257;
const MOD1: i64 = 1_000_000_007;
const BASE2: i64 = 263;
const MOD2: i64 = 1_000_000_009;

fn powmod(base: i64, mut exp: i64, modu: i64) -> i64 {
    let mut result = 1;
    let mut base = base % modu;
    while exp > 0 {
        if exp & 1 == 1 {
            result = (result * base) % modu;
        }
        exp >>= 1;
        base = (base * base) % modu;
    }
    result
}

fn prefix_hashes(arr: &[i64], pref_hash: &mut Vec<i64>, base: i64, modu: i64) {
    let mut hash = 0;
    for (i, &val) in arr.iter().enumerate() {
        hash = (hash * base + val) % modu;
        pref_hash[i] = hash;
    }
}

fn poly_hash(
    prefix_hashes_1: &[i64],
    prefix_hashes_2: &[i64],
    start: usize,
    len: usize,
) -> (i64, i64) {
    let mut hash1 = prefix_hashes_1[start + len - 1];
    if start > 0 {
        hash1 = (hash1 + MOD1
            - prefix_hashes_1[start - 1] * powmod(BASE1, len as i64, MOD1) % MOD1)
            % MOD1;
    }

    let mut hash2 = prefix_hashes_2[start + len - 1];
    if start > 0 {
        hash2 = (hash2 + MOD2
            - prefix_hashes_2[start - 1] * powmod(BASE2, len as i64, MOD2) % MOD2)
            % MOD2;
    }

    (hash1, hash2)
}

fn check(vec1: &[i64], vec2: &[i64], len: usize) -> bool {
    use std::collections::HashSet;
    let mut set = HashSet::new();

    let mut pref_hashes_1a = vec![0; vec1.len()];
    let mut pref_hashes_1b = vec![0; vec1.len()];
    let mut pref_hashes_2a = vec![0; vec2.len()];
    let mut pref_hashes_2b = vec![0; vec2.len()];

    prefix_hashes(&vec1, &mut pref_hashes_1a, BASE1, MOD1);
    prefix_hashes(&vec1, &mut pref_hashes_1b, BASE2, MOD2);
    prefix_hashes(&vec2, &mut pref_hashes_2a, BASE1, MOD1);
    prefix_hashes(&vec2, &mut pref_hashes_2b, BASE2, MOD2);

    for i in 0..=vec1.len() - len {
        set.insert(poly_hash(&pref_hashes_1a, &pref_hashes_1b, i, len));
    }

    for i in 0..=vec2.len() - len {
        if set.contains(&poly_hash(&pref_hashes_2a, &pref_hashes_2b, i, len)) {
            return true;
        }
    }

    false
}

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut scores_1 = Vec::with_capacity(n);

    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    scores_1.extend(
        input
            .trim()
            .split_whitespace()
            .map(|s| s.parse::<i64>().unwrap()),
    );

    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let m: usize = input.trim().parse().unwrap();
    let mut scores_2 = Vec::with_capacity(m);

    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    scores_2.extend(
        input
            .trim()
            .split_whitespace()
            .map(|s| s.parse::<i64>().unwrap()),
    );

    let mut result = 0;
    let mut left = 0;
    let mut right = std::cmp::min(n, m);

    while left <= right {
        let mid = (left + right) / 2;

        if check(&scores_1, &scores_2, mid) {
            result = std::cmp::max(mid, result);
            left = mid + 1;
        } else {
            if mid == 0 {
                break;
            }
            right = mid - 1;
        }
    }

    println!("{}", result);
}

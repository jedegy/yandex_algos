// https://contest.yandex.ru/contest/23991/problems/L/
use std::collections::HashMap;
use std::io;

const BASE: u64 = 31;
const MOD: u64 = u64::MAX;

fn get_hash(hashes: &[u64], powers: u64, i: usize, n: usize) -> u64 {
    let mut hash = hashes[i + n].wrapping_sub(hashes[i].wrapping_mul(powers).wrapping_rem(MOD));
    hash = (hash.wrapping_rem(MOD).wrapping_add(MOD)).wrapping_rem(MOD);
    hash
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut nums = input.trim().split_whitespace();
    let n: usize = nums.next().unwrap().parse().unwrap();
    let k: usize = nums.next().unwrap().parse().unwrap();

    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let s = input.trim();

    let mut map = HashMap::new();
    let mut result = HashMap::new();
    let mut hashes = vec![0u64; s.len() + 1];
    let mut powers = 1u64;
    for i in 1..=s.len() {
        hashes[i] = (hashes[i - 1].wrapping_mul(BASE) + s.chars().nth(i - 1).unwrap() as u64 - 'a' as u64 + 1).wrapping_rem(MOD);
        if i <= n {
            powers = (powers.wrapping_mul(BASE)).wrapping_rem(MOD);
        }
    }

    for i in 0..=s.len() - n {
        let hash = get_hash(&hashes, powers, i, n);
        let counter = map.entry(hash).or_insert(0);
        *counter += 1;
        if *counter == 1 {
            result.insert(hash, i);
        }
    }

    for (hash, count) in map.iter() {
        if *count >= k {
            print!("{} ", result[hash]);
        }
    }
}


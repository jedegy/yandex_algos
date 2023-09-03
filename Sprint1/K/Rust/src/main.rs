// https://contest.yandex.ru/contest/22449/problems/K/

use std::io;

fn to_list_form(mut n: u32) -> Vec<i16> {
    let mut result = Vec::new();

    while n != 0 {
        result.push((n % 10) as i16);
        n /= 10;
    }

    result.reverse();
    result
}

fn add_list_form(num1: &[i16], num2: &[i16]) -> Vec<i32> {
    let mut result = Vec::new();
    let mut carry = 0;

    let (mut i, mut j) = (num1.len() as isize - 1, num2.len() as isize - 1);

    while i >= 0 || j >= 0 || carry > 0 {
        let mut sum = carry;

        if i >= 0 {
            sum += num1[i as usize] as i32;
            i -= 1;
        }
        if j >= 0 {
            sum += num2[j as usize] as i32;
            j -= 1;
        }

        carry = sum / 10;
        sum %= 10;

        result.push(sum);
    }

    result.reverse();
    result
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let _n: u32 = input.trim().parse().unwrap();

    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let x: Vec<i16> = input
        .split_whitespace()
        .filter_map(|s| s.parse().ok())
        .collect();

    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let k: u32 = input.trim().parse().unwrap();

    let k_form = to_list_form(k);
    let summ = add_list_form(&x, &k_form);

    println!(
        "{}",
        summ.iter()
            .map(|&x| x.to_string())
            .collect::<Vec<String>>()
            .join(" ")
    );
}

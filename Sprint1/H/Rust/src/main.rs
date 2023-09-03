// https://contest.yandex.ru/contest/22449/problems/H/

use std::io;

fn bin_summ(num1: &str, num2: &str) -> String {
    let (mut i, mut j) = (num1.len(), num2.len());
    let mut carry = 0;
    let mut result = Vec::new();

    while i > 0 || j > 0 || carry > 0 {
        let mut sum = carry;

        if i > 0 {
            i -= 1;
            sum += num1.chars().nth(i).unwrap() as u32 - '0' as u32;
        }
        if j > 0 {
            j -= 1;
            sum += num2.chars().nth(j).unwrap() as u32 - '0' as u32;
        }

        carry = sum / 2;
        sum %= 2;

        result.push((sum as u8 + b'0') as char);
    }

    result.reverse();
    result.into_iter().collect()
}

fn main() -> io::Result<()> {
    let mut num1 = String::new();
    let mut num2 = String::new();

    io::stdin().read_line(&mut num1)?;
    io::stdin().read_line(&mut num2)?;

    let (num1, num2) = (num1.trim(), num2.trim());

    println!("{}", bin_summ(num1, num2));

    Ok(())
}
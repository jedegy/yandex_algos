/*
-- WORKING PRINCIPLE --
This program finds the longest common prefix of unpacked strings, where the input strings are given in a compressed format.

-- PROOF OF CORRECTNESS --
The algorithm's correctness is ensured by:
 1. Unpacking strings using a recursive approach, which correctly unfolds the compressed sequences.
 2.Sequentially comparing characters in the strings to determine the common prefix.

-- TIME COMPLEXITY --
1. Unpacking: In the worst case, where each character of the string multiplies the length of the string many times over (for example, "2[a2[b2[c...]]]"),
 the complexity of unpacking can reach O(k^d), where k is the length of the string after unpacking and d is the maximum depth of nesting.
2. Finding the largest common prefix between n strings with a maximum length of k will take O(n * k).
 The overall time complexity will be O(n * k^d + n * k).

-- SPACE COMPLEXITY --
1. The current common prefix can occupy O(k).
2. Recursive calls: The unpack function can recursively call itself depending on the nesting depth of the string.
 In the worst case, this may require O(d) additional stack space.
 The program's overall space complexity is O(k + d).
*/
use std::io::BufRead;

fn unpack(s: &str) -> String {
    let mut result = String::new();
    let mut chars = s.chars().enumerate();

    while let Some((i, c)) = chars.next() {
        if c.is_ascii_digit() {
            let count = c.to_digit(10).unwrap() as usize;

            let mut balance = 1;
            let start = i + 2;
            let mut end = start;

            while balance != 0 {
                match s.chars().nth(end).unwrap() {
                    '[' => balance += 1,
                    ']' => balance -= 1,
                    _ => {}
                }
                end += 1;
            }

            let sub = unpack(&s[start..end - 1]);
            for _ in 0..count {
                result.push_str(&sub);
            }

            // Skip characters we've already processed
            for _ in 0..(end - i - 1) {
                chars.next();
            }
        } else {
            result.push(c);
        }
    }

    result
}

fn update_prefix(prefix: &mut String, s: &str) {
    let common_prefix_length = prefix
        .chars()
        .zip(s.chars())
        .take_while(|(a, b)| a == b)
        .count();

    prefix.truncate(common_prefix_length);
}

fn main() {
    let mut lines = std::io::stdin().lock().lines();
    let n: usize = lines.next().unwrap().unwrap().parse().unwrap();

    let mut prefix = if n > 0 {
        unpack(&lines.next().unwrap().unwrap())
    } else {
        String::new()
    };

    for _ in 1..n {
        update_prefix(&mut prefix, &unpack(&lines.next().unwrap().unwrap()));
    }

    println!("{}", prefix);
}

// https://contest.yandex.ru/contest/26131/problems/C/

fn count_letters(s: &str) -> Vec<usize> {
    let mut alphabet = vec![0; 26];
    for ch in s.chars() {
        let idx = (ch as u32 - 'a' as u32) as usize;
        alphabet[idx] += 1;
    }
    alphabet
}

fn generate_chars(letter_idx: usize, count: usize) -> String {
    let char_to_insert = (letter_idx as u8 + b'a') as char;
    char_to_insert.to_string().repeat(count)
}

fn build_palindrome(count: &[usize]) -> String {
    let mut center_l = 0;
    let mut center_r = 0;
    let mut result = String::new();

    for (i, &count) in count.iter().enumerate() {
        if count == 0 {
            continue;
        }

        if center_l == center_r {
            let chars_to_insert = generate_chars(i, count);
            result.insert_str(center_l, &chars_to_insert);
            center_l += count / 2;
            center_r = if count % 2 == 0 {
                center_l
            } else {
                center_l + 1
            };
        } else {
            let half_char_count = count / 2;
            if half_char_count > 0 {
                let chars_to_insert = generate_chars(i, half_char_count);
                result.insert_str(center_l, &chars_to_insert);
                result.insert_str(center_r + half_char_count, &chars_to_insert);
                center_l = result.len() / 2;
                center_r = center_l + 1;
            }
        }
    }

    result
}

fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let s = s.trim();
    let count = count_letters(s);
    println!("{}", build_palindrome(&count));
}

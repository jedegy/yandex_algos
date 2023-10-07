// https://contest.yandex.ru/contest/25596/problems/N/

const INF: usize = 1000000;

fn restore_days_used_coupons(
    dp: &[Vec<usize>],
    cost: &[usize],
    used: &mut Vec<usize>,
    i: usize,
    j: usize,
) {
    if j >= i {
        return;
    }
    match (j, cost[i]) {
        (0, _) if i >= 1 => {
            if cost[i] > 500 || dp[i][j] == dp[i - 1][j + 1] {
                used.push(i);
                restore_days_used_coupons(dp, cost, used, i - 1, j + 1);
            } else {
                restore_days_used_coupons(dp, cost, used, i - 1, j);
            }
        }
        (_, costi) if costi <= 500 => {
            if dp[i - 1][j + 1] == dp[i][j] {
                used.push(i);
                restore_days_used_coupons(dp, cost, used, i - 1, j + 1);
            } else {
                restore_days_used_coupons(dp, cost, used, i - 1, j);
            }
        }
        (_, _) => {
            if dp[i - 1][j + 1] == dp[i][j] {
                used.push(i);
                restore_days_used_coupons(dp, cost, used, i - 1, j + 1);
            } else {
                restore_days_used_coupons(dp, cost, used, i - 1, j - 1);
            }
        }
    }
}

fn main() {
    let mut lines = std::io::stdin().lines();
    let n = lines.next().unwrap().unwrap().parse::<usize>().unwrap();
    let mut cost = vec![0; n + 1];

    for i in 0..n {
        cost[i + 1] = lines.next().unwrap().unwrap().parse::<usize>().unwrap();
    }

    if n == 1 {
        println!("{} 0", cost[1]);
        return;
    }

    let mut dp = vec![vec![INF; n + 2]; n + 1];
    for i in 0..=n {
        for j in 0..=i {
            dp[i][j] = match (j, cost[i]) {
                (0, _) if i == 0 => 0,
                (0, value) if i >= 1 => std::cmp::min(dp[i - 1][j + 1], dp[i - 1][j] + value),
                (_, value) if value > 500 => {
                    std::cmp::min(dp[i - 1][j + 1], dp[i - 1][j - 1] + value)
                }
                (_, value) => std::cmp::min(dp[i - 1][j + 1], dp[i - 1][j] + value),
            }
        }
    }

    let (total_cost, coupons) =
        dp[n]
            .iter()
            .enumerate()
            .take(n)
            .fold((INF, 0), |(min_cost, idx), (i, &x)| {
                if x < min_cost {
                    (x, i)
                } else {
                    (min_cost, idx)
                }
            });

    let mut used_coupons: Vec<usize> = Vec::new();
    restore_days_used_coupons(&dp, &cost, &mut used_coupons, n, coupons);

    println!("{} {}", total_cost, used_coupons.len());

    for coupon in used_coupons.iter().rev() {
        print!("{} ", coupon);
    }
    println!();
}

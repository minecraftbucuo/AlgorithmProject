// 1. https://atcoder.jp/contests/abc450/tasks/abc450_a
// use std::io;
//
// fn main() {
//     let mut input : String = String::new();
//     io::stdin().read_line(&mut input).unwrap();
//     let n : i32 = input.trim().parse::<i32>().unwrap();
//     let ans : Vec<String> = (1..=n).rev().map(|x| x.to_string()).collect();
//     println!("{}", ans.join(","))
// }

// 2. https://atcoder.jp/contests/abc450/tasks/abc450_b
// use std::io;
//
// fn main() {
//     let mut input = String::new();
//     io::stdin().read_line(&mut input).unwrap();
//     let n = input.trim().parse::<usize>().unwrap();
//
//     let mut ve = vec![vec![0i32; n + 1]; n + 1];
//
//     for i in 1..n {
//         input.clear();
//         io::stdin().read_line(&mut input).unwrap();
//         let mut it = input.split_whitespace().map(|x| x.parse::<i32>().unwrap());
//         for j in (i + 1)..=n {
//             ve[i][j] = it.next().unwrap();
//         }
//     }
//
//     let mut found = false;
//
//     for a in 1..=n {
//         for b in (a + 1)..=n {
//             for c in (b + 1)..=n {
//                 if ve[a][b] + ve[b][c] < ve[a][c] {
//                     found = true;
//                     break;
//                 }
//             }
//             if found {
//                 break;
//             }
//         }
//         if found {
//             break;
//         }
//     }
//
//     if found {
//         println!("Yes");
//     } else {
//         println!("No");
//     }
// }

// 3. https://www.luogu.com.cn/problem/AT_abc450_c
use std::io;
use std::collections::VecDeque;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let h : usize = it.next().unwrap().parse().unwrap();
    let w : usize = it.next().unwrap().parse().unwrap();

    let mut vis = vec![vec![false; w + 1]; h + 1];
    let mut grid = vec![vec![' '; w + 1]; h + 1];

    for i in 1..=h {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let it : Vec<char> = input.trim_end().chars().collect();
        for j in 1..=w {
            grid[i][j] = it[j - 1];
        }
    }

    let mut ans = 0;

    let dir = [(0, 1), (0, -1), (1, 0), (-1, 0)];

    for i in 1..=h {
        for j in 1..=w {
            if !vis[i][j] && grid[i][j] == '.' {
                let mut is = true;
                let mut q : VecDeque<(usize, usize)> = VecDeque::new();
                q.push_back((i, j));
                while let Some((x, y)) = q.pop_front() {
                    if vis[x][y] {
                        continue;
                    }
                    vis[x][y] = true;
                    if x == 1 || x == h || y == 1 || y == w {
                        is = false;
                    }
                    for (dx, dy) in dir {
                        let x = x as i32 + dx;
                        let y = y as i32 + dy;
                        if x < 1 || x > h as i32 || y < 1 || y > w as i32 ||
                            vis[x as usize][y as usize] || grid[x as usize][y as usize] == '#' {
                            continue;
                        }
                        q.push_back((x as usize, y as usize));
                    }
                }

                if is {
                    ans += 1;
                }
            }
        }
    }

    println!("{}", ans);
}

















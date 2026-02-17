use std::io::{self, BufWriter, Read, Write};

#[allow(dead_code)]
struct Scanner {
    buf: Vec<u8>,
    pos: usize,
}

#[allow(dead_code)]
impl Scanner {
    fn new() -> Self {
        let mut buf = Vec::new();
        io::stdin().read_to_end(&mut buf).ok();
        Self { buf, pos: 0 }
    }
    fn next<T: std::str::FromStr>(&mut self) -> T {
        while self.pos < self.buf.len() && self.buf[self.pos] <= b' ' {
            self.pos += 1;
        }
        let start = self.pos;
        while self.pos < self.buf.len() && self.buf[self.pos] > b' ' {
            self.pos += 1;
        }
        unsafe { std::str::from_utf8_unchecked(&self.buf[start..self.pos]) }
            .parse()
            .ok()
            .expect("parse error")
    }
    fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.next()).collect()
    }
    fn chars(&mut self) -> Vec<char> {
        self.next::<String>().chars().collect()
    }
}

#[allow(unused_macros)]
macro_rules! scan {
    ($sc:expr, $($t:ty),+) => { ($($sc.next::<$t>()),+) }
}

fn main() {
    let mut sc = Scanner::new();
    let out = &mut BufWriter::new(io::stdout().lock());
    solve(&mut sc, out);
    let _ = out.flush();
}

fn solve(sc: &mut Scanner, out: &mut impl Write) {}

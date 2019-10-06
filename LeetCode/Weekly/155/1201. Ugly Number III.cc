typedef long long lld;
const int MAXN = 2e9;

class Solution {
    int a, b, c;
    lld ab, ac, bc, abc;

public:
    int nthUglyNumber(int n, int A, int B, int C) {
        a=A, b=B, c=C;
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        init();

        int lo = 1;
        int hi = MAXN;
        while (lo < hi) {
            int x = lo + (hi - lo) / 2;
            int y = f(x);
            if (y < n) {
                lo = x + 1;
            } else {
                hi = x;
            }
        }
        return lo;
    }

private:
    // Principle of Inclusion Exclusion
    lld f(int num) {
        return 1LL * num/a + num/b + num/c - num/ab - num/ac - num/bc + num/abc;
    }

    lld gcd(lld a, lld b) { return b ? gcd(b, a % b) : a; }
    lld lcm(lld a, lld b) { return 1LL * a / gcd(a, b) * b; }

    void init() {
        ab = lcm(a, b);
        ac = lcm(a, c);
        bc = lcm(b, c);
        abc = lcm(a, bc);
    }
};

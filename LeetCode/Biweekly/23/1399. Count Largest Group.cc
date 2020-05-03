const int BASE = 10;
const int MAXS = 40;

class Solution {
public:
    int countLargestGroup(int n) {
        int cnt[MAXS]{ };
        for (int i = 1; i <= n; ++i) {
            ++cnt[digits(i)];
        }
        int best = *max_element(cnt, cnt+MAXS);
        int ret = 0;
        for (int i = 1; i < MAXS; ++i) {
            if (cnt[i] == best) ++ret;
        }
        return ret;
    }

private:
    int digits(int x) {
        int sum = 0;
        while (x) {
            sum += x % BASE;
            x /= BASE;
        }
        return sum;
    }
};

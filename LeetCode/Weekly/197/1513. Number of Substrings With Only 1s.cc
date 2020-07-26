typedef long long lld;
const int MOD = 1e9+7;

int cnt;
int ret;

class Solution {
public:
    int numSub(string s) {
        cnt = 0;
        ret = 0;
        for (char c: s) {
            if (c == '1') {
                ++cnt;
            } else if (cnt) {
                flush();
            }
        }
        if (cnt) {
            flush();
        }
        return ret;
    }

private:
    void flush() {
        ret = (ret + sum(cnt)) % MOD;
        cnt = 0;
    }

    int sum(int x) {
        return (1LL * x * (x + 1) / 2) % MOD;
    }
};

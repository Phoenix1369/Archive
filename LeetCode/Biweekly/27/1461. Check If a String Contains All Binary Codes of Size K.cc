#define CLR(x) memset((x), false, sizeof(x))
const int MAXN = (1 << 20) | 5;
bool seen[MAXN];
int N;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        N = s.size();
        CLR(seen);
        int mask = (1 << k) - 1;
        int t = 0;
        for (int i = 0; i < N; ++i) {
            t = (t << 1) | (s[i] - '0');
            t &= mask;
            if (i >= k-1) {
                seen[t] = true;
            }
        }
        for (int i = 0; i <= mask; ++i) {
            if (!seen[i]) return false;
        }
        return true;
    }
};

const int BASE = 10;
const int LOGN = 12;
int memo[LOGN];
bool seen[LOGN];
vector<int> D;

class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        D.clear();
        for (int i = 0; i < LOGN; ++i) {
            seen[i] = false;
        }

        // Unique digits
        memo[0] = 0;
        memo[1] = BASE - 1;
        for (int i = 2; i < LOGN; ++i) {
            memo[i] = memo[i-1] * (BASE - i + 1);
        }

        // Strictly shorter
        int M = N;
        int len = 0;
        int ret = 0;
        while (M) {
            ret += memo[len];
            D.push_back(M % BASE);
            M /= BASE;
            ++len;
        }

        // Prefix match
        for (int i = len-1; i >= 0; --i) {
            int beg = 0;
            int cnt = 0;
            if (i+1 == len) ++beg;
            for (int j = beg; j < D[i]; ++j) {
                if (!seen[j]) ++cnt;
            }

            // Any suffix
            int mul = 1;
            for (int j = 0; j < i; ++j) {
                mul *= (BASE - (len - i) - j);
            }
            ret += cnt * mul;

            if (seen[D[i]]) {
                break;
            }
            seen[D[i]] = true;

            // Perfect match
            if (!i) {
                ++ret;
            }
        }
        return N - ret;
    }
};

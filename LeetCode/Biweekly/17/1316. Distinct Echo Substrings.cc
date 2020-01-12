const int HASH = 131;
const int MAXN = 2005;
const int MOD = 1e9+7;
unordered_set<int> seen;
int H[MAXN];
string S;
int N;

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        S = move(text);
        N = S.size();
        seen.clear();
        seen.reserve(N);
        solve();
        return seen.size();
    }

private:
    void solve() {
        for (int i = 0; i < N; ++i) {
            int h = 0;
            int powH = 1;
            for (int j = i; j < N; ++j) {
                h = (1LL * HASH * h + S[j]) % MOD;
                H[j] = h;
                
                int l = (j - i + 1);
                if (l & 1) {
                    powH = 1LL * HASH * powH % MOD;
                    continue;
                }
                int val = (1LL * H[j] + MOD - (1LL * powH * H[j - l/2] % MOD)) % MOD;
                if (val == H[j - l/2]) {
                    seen.insert(val);
                }
            }
        }
    }
};

const int MAXA = 26;
const int MAXN = 105;

template <typename T>
using vec = vector<T>;

vec<vec<vec<int>>> dp;
// dp[i][j][k]
//  i: position of existing character
//  j: length of run of character "i"
//  k: number of characters deleted so far

vec<vec<int>> cnt;
vec<bool> seen;
string S;
int K, N;

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        S = move(s);
        N = S.size();
        K = k;
        if (N == K) {
            return 0;
        }
        S.insert(S.begin(), ' ');
        count();
        solve();
        return read();
    }

private:
    void count() {
        cnt.assign(N+1, vec<int>(MAXA, 0));
        for (int i = 1; i <= N; ++i) {
            ++cnt[i][S[i]-'a'];
            for (int j = 0; j < MAXA; ++j) {
                cnt[i][j] += cnt[i-1][j];
            }
        }
    }

    void solve() {
        dp.assign(N+1, vec<vec<int>>(N+1, vec<int>(K+1, N)));
        dp[1][1][0] = 1;
        for (int i = 1; i <= N; ++i) {
            // Delete [1, i-1]
            if (i-1 <= K) {
                dp[i][1][i-1] = 1;
            }
            // Assume existing prefix.
            seen.assign(MAXA, false);
            for (int l = i-1; l >= 1; --l) {
                int d = S[l]-'a';
                if (seen[d]) {
                    continue;
                }
                seen[d] = true;
                // Delete [l+1, i-1]
                int jC = cnt[l][d];
                for (int j = 1; j <= jC; ++j) {
                    int beg = i - l - 1;    // must delete (by assumption)
                    int rem = i - j - 1;    // may  delete (by choice)
                    int end = min(K, rem);
                    for (int k = beg; k <= end; ++k) {
                        if (S[i] == S[l]) {
                            int cur = dp[l][j][k-beg];
                            if (j > 1) {
                                // Remove old digits (if they exist)
                                cur -= to_string(j).size();
                            }
                            cur += to_string(j+1).size();
                            dp[i][j+1][k] = min(cur, dp[i][j+1][k]);
                        } else {
                            dp[i][1][k] = min(dp[l][j][k-beg] + 1, dp[i][1][k]);
                        }
                    }
                }
            }
        }
    }

    int read() {
        int ret = N;
        for (int i = 1; i <= N; ++i) {
            int d = S[i]-'a';
            int jC = cnt[i][d];
            int beg = i;
            for (int j = 1; j <= jC; ++j) {
                // Delete enough characters to create run-length K.
                while (cnt[i][d] - cnt[beg][d] < j) --beg;
                int kS = i - beg - j;
                for (int k = kS; k <= K; ++k) {
                    if ((K-k) < (N-i)) {
                        continue;
                    }
                    ret = min(dp[i][j][k], ret);
                }
            }
        }
        return ret;
    }
};

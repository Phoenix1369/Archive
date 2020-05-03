#define CLR(x) memset((x), 0, sizeof (x))
const int MAXM = 55;
const int MAXN = 505;
const int MOD = 1e9+7;
int dp[MAXN][MAXM][2][2];
int lps[MAXM];
string S, T;
string E;
int M, N;

class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        N = n;
        M = evil.size();
        S = move(s1);
        T = move(s2);
        E = move(evil);
        CLR(dp);
        preprocess();
        return dfs(0, 0, true, true);
    }

private:
    int dfs(int i, int j, bool f1, bool f2) {
        // Digit DP
        if (j == M) return 0;
        if (i == N) return 1;
        if (dp[i][j][f1][f2]) {
            return dp[i][j][f1][f2];
        }
        int lo = (f1) ? S[i] : 'a';
        int hi = (f2) ? T[i] : 'z';
        int ret = 0;
        for (char c = lo; c <= hi; ++c) {
            int nj = j;
            while (nj && (c != E[nj])) {
                nj = lps[nj-1];
            }
            if (c == E[nj]) {
                ++nj;
            } else {
                nj = 0;
            }
            bool g1 = (f1 && (c == S[i]));
            bool g2 = (f2 && (c == T[i]));
            ret = (1LL * dfs(i+1, nj, g1, g2) + ret) % MOD;
        }
        return dp[i][j][f1][f2] = ret;    
    }
    
    void preprocess() {
        // KMP Longest Prefix Suffix
        lps[0] = 0;
        int j = 0;
        for (int i = 1; i < M; ++i) {
            while (j && (E[i] != E[j])) {
                j = lps[j-1];
            }
            if (E[i] == E[j]) {
                lps[i] = ++j;
            } else {
                lps[i] = 0;
            }
        }
    }
};

const int MAXN = 105;
const int NOPE = -1;
int dp[MAXN][MAXN][MAXN];
string S;
int K, N;

class Solution {
public:
    int palindromePartition(string s, int k) {
        S = move(s);
        N = S.size();
        K = k;
        init();
        return dfs(0, N-1, K);
    }

private:
    int dfs(int l, int r, int k) {
        if (l > r) {
            return 0;
        }
        if (dp[l][r][k] != NOPE) {
            return dp[l][r][k];
        }
        if (l == r) {
            return dp[l][r][k] = (k > 1) ? MAXN : 0;
        }
        if (k == 1) {
            int add = (S[l] != S[r]) ? 1 : 0;
            return dp[l][r][k] = dfs(l+1, r-1, 1) + add;
        }
        int best = MAXN;
        for (int m = l; m < r; ++m) {
            int a = dfs(l, m, k-1) + dfs(m+1, r, 1);
            int b = dfs(l, m, 1) + dfs(m+1, r, k-1);
            best = min(min(a, b), best);
        }
        return dp[l][r][k] = best;
    }
    
    void init() {
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                for (int k = 0; k <= K; ++k) {
                    dp[i][j][k] = NOPE;
                }
            }
        }
    }
};

/*
"abc"
2
"aabbc"
3
"leetcode"
8
>> 1
>> 0
>> 0
*/

const int MAXN = 1005;
const int NOPE = -1;
int dp[MAXN][MAXN];

class Solution {
    string S;
    int N;
    
public:
    bool isValidPalindrome(string s, int k) {
        S = move(s);
        N = S.size();
        init();
        return (dfs(0, N-1) <= k);
    }
    
private:
    int dfs(int l, int r) {
        if (dp[l][r] != NOPE) {
            return dp[l][r];
        }
        if (l >= r) {
            return dp[l][r] = 0;
        }
        if (S[l] == S[r]) {
            return dp[l][r] = dfs(l+1, r-1);
        }
        return dp[l][r] = min(dfs(l+1, r), dfs(l, r-1)) + 1;
    }
    
    void init() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = NOPE;
            }
        }
    }
};

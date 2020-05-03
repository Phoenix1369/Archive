typedef long long lld;
const int BASE = 10;
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int dp[MAXN];
string S;
int K, N;

class Solution {
public:
    int numberOfArrays(string s, int k) {
        S = move(s);
        K = k;
        N = S.size();
        init();
        return dfs(0);
    }

private:
    int dfs(int pos) {
        if (pos == N) return 1;
        if (S[pos] == '0') return 0;
        if (dp[pos] != -1) {
            return dp[pos];
        }
        
        lld num = 0;
        int ret = 0;
        for(int nxt = pos; nxt < N; ++nxt) {
            num = 1LL * BASE * num + S[nxt] - '0';
            if (num > K) break;
            ret = (dfs(nxt+1) + ret) % MOD;
        }
        return dp[pos] = ret;
    }
    
    void init() {
        for (int i = 0; i <= N; ++i) {
            dp[i] = -1;
        }
    }
};

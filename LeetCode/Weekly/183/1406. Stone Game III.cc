const int INFN = 5e7+5;
const int MAXN = 5e4+5;
int dp[MAXN][2];
vector<int> A;
int N;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        A = move(stoneValue);
        N = A.size();
        init();
        int ret = dfs(0, 0);
        return
            (ret > 0) ? "Alice" :
            (ret < 0) ? "Bob" : "Tie";
    }

private:
    int dfs(int pos, int turn) {
        if (pos == N) {
            return 0;
        }
        if (dp[pos][turn] != INFN) {
            return dp[pos][turn];
        }
        int ans = -INFN;
        int sum = 0;
        for (int i = 0; (i < 3) && (pos + i < N); ++i) {
            sum += A[pos + i];
            ans = max(sum - dfs(pos + i + 1, turn ^ 1), ans);
        }
        return dp[pos][turn] = ans;
    }
    
    void init() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 2; ++j) {
                dp[i][j] = INFN;
            }
        }
    }
};

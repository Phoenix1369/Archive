const int MAXN = 105;
const int NOPE = -1;
int dp[MAXN][MAXN];
vector<int> A;
int N;

class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        A = move(arr);
        N = A.size();
        init();
        return dfs(0, N-1);
    }

private:
    int dfs(int l, int r) {
        if (l >= r) {
            return 1;
        }
        if (dp[l][r] != NOPE) {
            return dp[l][r];
        }
        int res = N;
        if (A[l] == A[r]) {
            res = min(dfs(l+1, r-1), res);
        }
        for (int i = l; i < r; ++i) {
            res = min(dfs(l, i) + dfs(i+1, r), res);
        }
        return dp[l][r] = res;
    }

    void init() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = NOPE;
            }
        }
    }
};

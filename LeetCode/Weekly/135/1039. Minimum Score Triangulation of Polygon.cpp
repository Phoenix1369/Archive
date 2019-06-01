const int INFN = 1e8+5;
const int MAXN = 55;
int dp[MAXN][MAXN];

class Solution {
    vector<int> A;
    int N;

public:
    int minScoreTriangulation(vector<int>& A) {
        N = A.size();
        this->A = move(A);
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                dp[i][j] = INFN;
            }
        }
        return dfs(0, N-1);
    }

private:
    int dfs(int l, int r) {
        if ((r - l) == 1) {
            return 0;
        }
        if (dp[l][r] != INFN) {
            return dp[l][r];
        }
        int ret = INFN;
        for (int m = l+1; m < r; ++m) {
            ret = min(A[l] * A[m] * A[r] + dfs(l, m) + dfs(m, r), ret);
        }
        return dp[l][r] = ret;
    }
};

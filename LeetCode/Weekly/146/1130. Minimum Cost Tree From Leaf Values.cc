typedef long long lld;
const int MAXN = 45;
const lld INFN = 1LL<<60;
lld dp[MAXN][MAXN];
lld pd[MAXN][MAXN];
int mx[MAXN][MAXN];
vector<int> A;
int N;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        A = move(arr);
        N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = INFN;
                pd[i][j] = INFN;
            }
        }
        for (int i = 0; i < N; ++i) {
            mx[i][i] = A[i];
            for (int j = i+1; j < N; ++j) {
                mx[i][j] = max(mx[i][j-1], A[j]);
            }
        }
        return dfs(0, N-1);
    }

private:
    lld dfs(int l, int r) {
        if (dp[l][r] != INFN) {
            return dp[l][r];
        }
        if (l == r) {
            pd[l][r] = A[l];
            return dp[l][r] = 0;
        }
        if (r - l == 1) {
            pd[l][r] = A[l] * A[r];
            return dp[l][r] = pd[l][r];
        }
        for (int m = l; m < r; ++m) {
            int lhs = dfs(l, m);
            int rhs = dfs(m+1, r);
            int sum = lhs + rhs + mx[l][m] * mx[m+1][r];
            if (sum < dp[l][r]) {
                dp[l][r] = sum;
            }
        }
        return dp[l][r];
    }
};

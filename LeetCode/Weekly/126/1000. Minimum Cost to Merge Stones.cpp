#define ALL(x) (x).begin(), (x).end()
const int INFN = 1e9+7;
const int MAXN = 35;

class Solution {
    int stones[MAXN];
    int dp[MAXN][MAXN];
    int K, N;
public:
    int mergeStones(vector<int>& stones, int K) {
        this->K = K;
        N = stones.size();
        copy(ALL(stones), this->stones + 1);
        if ((K != 2) && ((N - 1) % (K - 1))) {
            return -1;
        }
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                dp[i][j] = -1;
            }
        }
        return dfs(1, N);
    }

private:
    int dfs(int l, int r) {
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        int span = r - l + 1;
        if (span < K) {
            return dp[l][r] = 0;
        }
        int ret = INFN;
        // Ensure only subproblems which lead to the maximum
        // amount of merges done on this segment are considered.
        int merges = (span - 1) / (K - 1);
        int remain = (span - 1) % (K - 1);
        bool whole = !remain;
        for (int m = l; m < r; ++m) {
            int go = (m - l) / (K - 1) +
                (r - (m + 1)) / (K - 1);
            if (go + whole < merges) {
                continue;
            }
            int sum = dfs(l, m) + dfs(m+1, r);
            if (sum) {
                ret = min(sum, ret);
            }
        }
        if (ret == INFN) {
            ret = 0;
        }
        if (whole) {
            ret += accumulate(stones + l, stones + r + 1, 0);
        }
        return dp[l][r] = ret;
    }
};
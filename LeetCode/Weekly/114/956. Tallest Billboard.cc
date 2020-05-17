#define ALL(x) (x).begin(), (x).end()
const int MAXS = 1e4+5;
int dp[2][MAXS];
int N;

// See USACO 1998 Subset Sums.

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        N = rods.size();
        init();
        int sum = accumulate(ALL(rods), 0);
        int mid = sum;
        dp[0][mid] = 0;
        for (int h = 0, i = 1; h < N; ++h, i ^= 1) {
            sum -= rods[h];
            for (int j = mid-sum; j <= mid+sum; ++j) {
                dp[i][j] = max(dp[i^1][j-rods[h]], dp[i^1][j+rods[h]] + rods[h]);
                dp[i][j] = max(dp[i^1][j], dp[i][j]);
                if (dp[i][j] < 0) {
                    dp[i][j] = -MAXS;
                }
            }
        }
        return dp[N&1][mid];
    }

private:
    void init() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < MAXS; ++j) {
                dp[i][j] = -MAXS;
            }
        }
    }
};

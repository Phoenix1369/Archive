#define ALL(x) (x).begin(), (x).end()
#define CLR(x) memset((x), -1, sizeof(x))
const int INFN = 1e6+5;
const int MAXN = 105;
int dp[MAXN][MAXN][MAXN];
vector<int> A;
vector<int> P;
int K, N;

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        A = move(houses);
        N = A.size();
        K = k;
        init();
        return dfs(1, N, k);
    }

private:
    int dfs(int ls, int rs, int k) {
        if (dp[ls][rs][k] != -1) {
            return dp[ls][rs][k];
        }
        int cur = INFN;
        for (int m = ls; m < rs; ++m) {
            cur = min(dfs(ls, m, 1) + dfs(m+1, rs, k-1), cur);
        }
        return dp[ls][rs][k] = cur;
    }

    int get(int ls, int rs) {
        int ms = (ls + rs) / 2;
        int l = (ms - ls) * A[ms] - (P[ms-1] - P[ls-1]);
        int r = (P[rs] - P[ms]) - (rs - ms) * A[ms];
        return (l + r);
    }

    void init() {
        // A
        sort(ALL(A));
        A.insert(A.begin(), 0);
        // P
        P.clear();
        P.reserve(N+1);
        P.push_back(0);
        for (int i = 1; i <= N; ++i) {
            P.push_back(A[i] + P.back());
        }
        // dp
        CLR(dp);
        for (int i = 1; i <= N; ++i) {
            for (int j = i+1; j <= N; ++j) {
                dp[i][j][1] = get(i, j);
            }
            for (int k = 1; k <= K; ++k) {
                dp[i][i][k] = 0;
            }
        }
    }
};

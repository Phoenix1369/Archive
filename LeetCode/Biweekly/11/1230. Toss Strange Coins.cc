const int MAXN = 1005;
double dp[MAXN][MAXN];
vector<double> P;
int K, N;

class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        P = move(prob);
        N = P.size();
        K = target;
        init();
        return dfs(0, 0);
    }

private:
    double dfs(int pos, int cnt) {
        if (cnt == K) {
            double res = 1.0;
            for (int i = pos; i < N; ++i) {
                res *= (1 - P[pos]);
            }
            return res;
        }
        if (pos == N) {
            return 0.0;
        }
        if (dp[pos][cnt] >= 0.0) {
            return dp[pos][cnt];
        }
        return dp[pos][cnt] =
            dfs(pos+1, cnt  ) * (1 - P[pos]) +
            dfs(pos+1, cnt+1) * P[pos];
    }
    
    void init() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < K; ++j) {
                dp[i][j] = -1.0;
            }
        }
    }
};

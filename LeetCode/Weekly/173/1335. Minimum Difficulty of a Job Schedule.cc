const int MAXA = 3e5+5;
const int MAXD = 11;
const int MAXN = 305;
int dp[MAXN][MAXD];
int A[MAXN];
int P[MAXN][MAXN];
int D, N;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        N = jobDifficulty.size();
        D = d;
        if (N < D) {
            return -1;
        }
        
        A[0] = 0;
        for (int i = 0; i < N; ++i) {
            A[i+1] = jobDifficulty[i];
        }
        init();
        
        dp[0][0] = 0;
        for (int i = 1; i <= N; ++i) {
            dp[i][1] = P[1][i];
            int maxD = min(i, D);
            for (int j = 2; j <= maxD; ++j) {
                dp[i][j] = MAXA;
                for (int k = j; k <= i; ++k) {
                    dp[i][j] = min(dp[k-1][j-1] + P[k][i], dp[i][j]);
                }
            }
        }
        return dp[N][D];
    }

private:
    void init() {
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= D; ++j) {
                dp[i][j] = -1;
            }
        }
        for (int i = 1; i <= N; ++i) {
            P[i][i-1] = 0;
            for (int j = i; j <= N; ++j) {
                P[i][j] = max(P[i][j-1], A[j]);
            }
        }
    }
};

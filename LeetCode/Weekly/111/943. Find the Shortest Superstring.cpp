const int INFN = 1e9+7;
const int MAXN = 12;
const int EXPN = 1 << MAXN;
int dp[EXPN][MAXN];     // dp[i][j] = length of all strings in set "i", ending on string "j"
int path[EXPN][MAXN];   // path[i][j] = index of previous string for dp[i][j]
int G[MAXN][MAXN];      // G[i][j] = minimal length increase for merge(i, j)
string res;

class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        // Initialization
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    G[i][j] = 0;
                } else {
                    merge_cat(A, i, j);
                }
            }
        }
        int E = 1 << N;
        for (int i = 0; i < E; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = path[i][j] = INFN;
            }
        }

        // Solve (DP)
        for (int mask = 1; mask < E; ++mask) {
            for (int i = 0; i < N; ++i) if ((mask >> i) & 1) {
                // Singleton
                if (mask == (1 << i)) {
                    dp[mask][i] = A[i].size();
                    path[mask][i] = -1;
                    break;
                }

                // Transitions
                for (int j = 0; j < N; ++j) if ((j != i) && ((mask >> j) & 1)) {
                    int prev = mask & ~(1 << i);
                    int val = dp[prev][j] + G[j][i];
                    if (val < dp[mask][i]) {
                        dp[mask][i] = val;
                        path[mask][i] = j;
                    }
                }
            }
        }

        // Recover solution
        int best = 0;
        for (int i = 0; i < N; ++i) {
            if (dp[E-1][i] < dp[E-1][best]) {
                best = i;
            }
        }
        res.clear();
        dfs(A, E-1, best);
        return res;
    }

private:
    void dfs(const vector<string>& A, int mask, int cur) {
        int pos = path[mask][cur];
        if (pos < 0) {
            res = A[cur];
            return;
        }
        int prev = mask & ~(1 << cur);
        dfs(A, prev, pos);
        int L = A[cur].size();
        for (int i = L - G[pos][cur]; i < L; ++i) {
            res.push_back(A[cur][i]);
        }
    }

    void merge_cat(const vector<string>& A, int i, int j) {
        // Merge A[i] + A[j], minimizing length of sum.
        int si = A[i].size();
        int sj = A[j].size();
        for (int k = min(si, sj) - 1; k >= 0; --k) {
            if (A[i].compare(si - k, string::npos, A[j], 0, k) == 0) {
                G[i][j] = sj - k;
                break;
            }
        }
    }
};

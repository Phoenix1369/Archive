const int MAXN = 505;
int cache[2][MAXN];

class Solution {
    int M, N;

public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        N = A.size();
        M = B.size();
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j <= M; ++j) {
                cache[i][j] = 0;
            }
        }
        for (int i = 1; i <= N; ++i) {
            int cur = (i & 1);
            int pre = (cur ^ 1);
            for (int j = 1; j <= M; ++j) {
                if (A[i-1] != B[j-1]) {
                    cache[cur][j] = max(cache[pre][j], cache[cur][j-1]);
                } else {
                    cache[cur][j] = cache[pre][j-1] + 1;
                }
            }
        }
        return cache[N & 1][M];
    }
};


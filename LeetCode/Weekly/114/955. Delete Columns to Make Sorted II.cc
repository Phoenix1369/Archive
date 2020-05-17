#define ALL(x) (x).begin(), (x).end()
const int MAXM = 105;
int M, N;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int N = A.size();
        int M = A[0].size();
        vector<bool> pre(N, true);
        int ret = 0;
        for (int j = 0; j < M; ++j) {
            bool done = true;
            bool drop = false;
            vector<bool> nxt(ALL(pre));
            for (int i = 1; i < N; ++i) {
                if (!pre[i]) continue;
                if (A[i-1][j] < A[i][j]) {
                    nxt[i] = false;
                    continue;
                }
                if (A[i-1][j] > A[i][j]) {
                    drop = true;
                }
                done = false;
            }
            if (done) break;
            if (drop) ++ret;
            else pre = move(nxt);
        }
        return ret;
    }
};

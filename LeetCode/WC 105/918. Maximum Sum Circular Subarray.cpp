const int MAXN = 6e4+5;
int C[MAXN];
int Q[MAXN];
int head, tail;
int ret;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        // Prefix sum array
        int N = A.size();
        C[0] = 0;
        for (int i = 1; i <= N; ++i) {
            C[i] = C[i+N] = A[i-1];
        }
        int N2 = N * 2;
        for (int i = 1; i <= N2; ++i) {
            C[i] += C[i-1];
        }

        // Monotonic queue
        ret = -MAXN;
        head = tail = 0;
        Q[tail++] = 0;
        for (int i = 1; i <= N2; ++i) {
            while ((head < tail) && (i - Q[head] > N)) {
                ++head;
            }
            ret = max(C[i] - C[Q[head]], ret);
            // Subtract smallest prefix in [i-N, i-1] to maximize sum
            while ((head < tail) && (C[i] <= C[Q[tail-1]])) {
                --tail;
            }
            Q[tail++] = i;
        }
        return ret;
    }
};


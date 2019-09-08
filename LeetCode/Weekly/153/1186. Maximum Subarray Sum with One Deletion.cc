const int INFN = 1e9+7;
const int MAXN = 1e5+5;
int pre[MAXN];
int suf[MAXN];
int A[MAXN];
int N;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        N = arr.size();
        
        // Prefix sum.
        A[0] = 0;
        for (int i = 1; i <= N; ++i) {
            A[i] = A[i-1] + arr[i-1];
        }
        
        // Prefix max.
        pre[N+1] = -INFN;
        for (int i = N; i >= 1; --i) {
            pre[i] = max(pre[i+1], A[i]);
        }
        pre[N+1] = 0;
        
        // Suffix min.
        suf[0] = 0;
        for (int i = 1; i <= N; ++i) {
            suf[i] = min(suf[i-1], A[i]);
        }
        
        // Solve.
        int ret = -INFN;
        for (int i = 1; i <= N; ++i) {            
            int cur = arr[i-1];
            
            // Non-empty prefix.
            if (i < N) {
                ret = max(pre[i+1] - suf[i-1] - cur, ret);
            }
            
            // Non-empty suffix
            if (i >= 2) {
                ret = max(pre[i] - suf[i-2] - cur, ret);
            }
            
            // No deletions
            ret = max(pre[i] - suf[i-1], ret);
        }
        return ret;
    }
};

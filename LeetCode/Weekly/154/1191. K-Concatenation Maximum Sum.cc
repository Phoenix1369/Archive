const int MAXN = 2e5+5;
const int MOD = 1e9+7;
typedef long long lld;
int A[MAXN];
int N, N2;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        N = arr.size();
        N2 = min(2, k) * N;
        
        A[0] = 0;
        for (int i = 1; i <= N; ++i) {
            A[i] = A[i+N] = arr[i-1];
        }
        
        int pre = max_prefix();
        int suf = max_suffix();
        
        for (int i = 1; i <= N2; ++i) {
            A[i] += A[i-1];
        }        
        
        lld res = max_subarray();
        if (k >= 2) {
            res = max(1LL * A[N] * (k-2) + pre + suf, res);
        }
        
        int ret = res % MOD;
        return ret;
    }
    
private:
    int max_prefix() {
        int sum = 0;
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            sum += A[i];
            res = max(sum, res);
        }
        return res;
    }
        
    int max_suffix() {
        int sum = 0;
        int res = 0;
        for (int i = N; i >= 1; --i) {
            sum += A[i];
            res = max(sum, res);
        }
        return res;
    }
    
    lld max_subarray() {
        lld res = 0;
        int prv = 0;
        for (int i = 1; i <= N2; ++i) {
            res = max(1LL * A[i] - A[prv], res);
            if (A[i] < A[prv]) {
                prv = i;
            }
        }
        return res;
    }
};

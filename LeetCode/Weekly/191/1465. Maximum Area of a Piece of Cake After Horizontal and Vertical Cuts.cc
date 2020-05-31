#define ALL(x) (x).begin(), (x).end()
const int MOD = 1e9+7;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        int dh = solve(h, hc);
        int dv = solve(w, vc);
        int ret = 1LL * dh * dv % MOD;
        return ret;
    }

private:
    int solve(int k, vector<int>& A) {
        int res = 0;
        A.push_back(0);
        A.push_back(k);
        int N = A.size();
        sort(ALL(A));
        for (int i = 1; i < N; ++i) {
            res = max(A[i] - A[i-1], res);
        }
        return res;
    }
};

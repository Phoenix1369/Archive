const int MAXN = 4e4+5;
int f[4][MAXN];

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int N = arr1.size();
        for (int i = 0; i < N; ++i) {
            f[0][i] = arr1[i] + arr2[i] + i;
            f[1][i] = arr1[i] - arr2[i] + i;
            f[2][i] = arr1[i] + arr2[i] - i;
            f[3][i] = arr1[i] - arr2[i] - i;
        }
        int ret = 0;
        for (int k = 0; k < 4; ++k) {
            int mn = f[k][0];
            int mx = f[k][0];
            for (int i = 0; i < N; ++i) {
                mn = min(f[k][i], mn);
                mx = max(f[k][i], mx);
            }
            ret = max(mx - mn, ret);
        }
        return ret;
    }
};

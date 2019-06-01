const int MAXN = 3e4+5;

class Solution {
    int suf[MAXN];
    
public:
    int partitionDisjoint(vector<int>& A) {
        int n = (int)A.size();
        suf[n] = 1e6+5;
        for (int i = n-1; i >= 0; --i) {
            suf[i] = min(A[i], suf[i+1]);
        }
        int cur = A[0];
        for (int i = 1; i < n; ++i) {
            if (cur <= suf[i]) {
                return i;
            }
            cur = max(A[i], cur);
        }
    }
};

const int MAXN = 3e4+5;
int cnt[MAXN]{ };

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        for (int i = 0; i < MAXN; ++i) {
            cnt[i] = 0;
        }
        cnt[0] = 1;
        int ret=0, sum=0;
        int n = (int)A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i]) ++sum;
            if (sum >= S) {
                ret += cnt[sum-S];
            }
            ++cnt[sum];
        }
        return ret;
    }
};

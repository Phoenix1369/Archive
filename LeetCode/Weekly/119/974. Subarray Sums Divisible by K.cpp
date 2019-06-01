class Solution {
    map<int,int> cnt;
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sum = 0;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            sum = ((sum + A[i]) % K + K) % K;
            ++cnt[sum];
        }
        int ret = 0;
        if (cnt.count(0)) {
            ret += cnt.at(0);
        }
        sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = ((sum + A[i]) % K + K) % K;
            if (!--cnt[sum]) {
                cnt.erase(sum);
            } else {
                ret += cnt.at(sum);
            }
        }
        return ret;
    }
};

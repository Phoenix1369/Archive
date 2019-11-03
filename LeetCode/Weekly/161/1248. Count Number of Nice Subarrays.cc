typedef long long lld;
const int MAXN = 5e4+5;
int cnt[MAXN]{ };
int pre[MAXN]{ };
int N;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int K) {
        N = nums.size();
        cnt[0] = 0;
        pre[0] = 0;
        for (int i = 1; i <= N; ++i) {
            cnt[i] = 0;
            pre[i] = pre[i-1] + (nums[i-1] & 1);
        }
        lld ret = 0LL;
        ++cnt[pre[0]];
        for (int i = 1; i <= N; ++i) {
            if (pre[i] >= K) {
                ret += cnt[pre[i]-K];
            }
            ++cnt[pre[i]];
        }
        return ret;
    }
};

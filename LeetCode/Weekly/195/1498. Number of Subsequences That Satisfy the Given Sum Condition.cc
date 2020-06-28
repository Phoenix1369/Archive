#define CLR(x) memset((x), 0, sizeof(x))
const int MAXA = 1e6+5;
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int cnt[MAXA]{ };
int two[MAXN]{ };
int N;

// Iterate over the minimum value m of the subsequence:
// (all subsets in [m] - 1) * (all subsets in [m+1, target-m])

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        N = nums.size();
        init();
        for (int x: nums) ++cnt[x];
        for (int i = 1; i < MAXA; ++i) {
            cnt[i] += cnt[i-1];
        }
        int ret = 0;
        for (int i=1, j=target-1; i <= j; ++i, --j) {
            int cur = cnt[i] - cnt[i-1];
            if (cur == 0) continue;
            int val = 1LL * (two[cur] + MOD - 1) * two[cnt[j] - cnt[i]] % MOD;
            ret = (1LL * ret + val) % MOD;
        }
        return ret;
    }

private:
    void init() {
        CLR(cnt);
        two[0] = 1;
        for (int i = 1; i <= N; ++i) {
            two[i] = 2LL * two[i-1] % MOD;
        }
    }
};

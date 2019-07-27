const int MAXT = 501;
const int MOD = 60;
int cnt[MAXT];

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for (int i = 0; i < MAXT; ++i) {
            cnt[i] = 0;
        }
        int N = time.size();
        for (int dur: time) {
            ++cnt[dur];
        }
        int ret = 0;
        for (int i = 1; i < MAXT; ++i) if (cnt[i]) {
            int r = i % MOD;
            int q = MOD - r;
            for (int j = q; j < MAXT; j += MOD) {
                ret += cnt[i] * (cnt[j] - (i == j));
            }
        }
        return ret / 2;
    }
};

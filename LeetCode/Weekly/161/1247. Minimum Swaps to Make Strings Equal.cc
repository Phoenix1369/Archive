class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int N = s1.size();
        int sum[2]{ };
        for (int i = 0; i < N; ++i) {
            if (s1[i] != s2[i]) {
                ++sum[s1[i]-'x'];
            }
        }
        // xx -> xy
        // yy    xy
        int ret = sum[0] / 2 + sum[1] / 2;
        sum[0] &= 1;
        sum[1] &= 1;
        if (sum[0] ^ sum[1]) {
            return -1;
        }
        if (sum[0]) {
            // xy -> yy -> xy
            // yx    xx    xy
            ret += 2;
        }
        return ret;
    }
};

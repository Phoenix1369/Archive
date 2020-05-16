class Solution {
public:
    int maxPower(string s) {
        int N = s.size();
        int cnt = 1;
        int ret = 0;
        for (int i = 1; i < N; ++i) {
            if (s[i] != s[i-1]) {
                ret = max(cnt, ret);
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        ret = max(cnt, ret);
        return ret;
    }
};

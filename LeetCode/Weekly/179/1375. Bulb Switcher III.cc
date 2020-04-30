class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int N = light.size();
        int mx = 0;
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            mx = max(light[i], mx);
            if (mx == (i+1)) ++ret;
        }
        return ret;
    }
};

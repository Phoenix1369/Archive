class Solution {
public:
    int minSwaps(vector<int>& data) {
        int N = data.size();
        int one = 0;
        for (int i = 0; i < N; ++i) {
            if (data[i]) ++one;
        }
        int cnt = 0;
        int ret = N;
        for (int i = 0; i < N; ++i) {
            cnt += data[i];
            if (i >= one) cnt -= data[i-one];
            if (i+1 >= one) {
                ret = min(one - cnt, ret);
            }
        }
        return ret;
    }
};

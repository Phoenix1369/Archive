#define ALL(x) (x).begin(), (x).end()

class Solution {
    vector<int> sorted;
public:
    int heightChecker(vector<int>& heights) {
        int N = heights.size();
        sorted = heights;
        sort(ALL(sorted));
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            if (sorted[i] != heights[i]) {
                ++ret;
            }
        }
        return ret;
    }
};

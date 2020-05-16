class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int M = target.size();
        vector<string> ret;
        for (int i = 1, j = 0; (i <= n) && (j < M); ++i) {
            ret.push_back("Push");
            if (i < target[j]) {
                ret.push_back("Pop");
            } else {
                ++j;
            }
        }
        return ret;
    }
};

#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ret = 0;
        if (!left.empty()) {
            ret = *max_element(ALL(left));
        }
        if (!right.empty()) {
            ret = max(n - *min_element(ALL(right)), ret);
        }
        return ret;
    }
};

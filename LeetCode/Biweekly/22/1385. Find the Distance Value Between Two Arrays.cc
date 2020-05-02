#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ret = 0;
        for (int x: arr1) {
            if (none_of(ALL(arr2), [&x, &d](int y) {
                return abs(x - y) <= d;
            })) ++ret;
        }
        return ret;
    }
};

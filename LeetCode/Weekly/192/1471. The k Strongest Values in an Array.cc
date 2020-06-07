#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(ALL(arr));
        int m = arr[(n - 1) / 2];
        vector<int> ret = arr;
        sort(ALL(ret), [&m](int lhs, int rhs) {
            int ld = abs(lhs - m);
            int rd = abs(rhs - m);
            return (ld != rd) ? (ld > rd) : (lhs > rhs);
        });
        ret.erase(ret.begin() + k, ret.end());
        return ret;
    }
};

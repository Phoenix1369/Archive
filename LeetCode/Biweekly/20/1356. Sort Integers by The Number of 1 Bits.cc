#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(ALL(arr), [](int lhs, int rhs) {
            int lcnt = bitcount(lhs);
            int rcnt = bitcount(rhs);
            return (lcnt != rcnt) ? (lcnt < rcnt) : (lhs < rhs);
        });
        return arr;
    }

private:
    static int bitcount(int x) {
        return (x) ? __builtin_popcount(x) : 0;
    }
};

#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(ALL(target));
        sort(ALL(arr));
        return (target == arr);
    }
};

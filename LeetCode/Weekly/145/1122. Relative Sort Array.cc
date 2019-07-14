#define ALL(x) (x).begin(), (x).end()
map<int,int> pos;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        pos.clear();
        int n2 = arr2.size();
        for (int i = 0; i < n2; ++i) {
            pos[arr2[i]] = i;
        }
        sort(ALL(arr1), [&](int lhs, int rhs) {
            int pl = pos.count(lhs);
            int pr = pos.count(rhs);
            if (pl && pr) {
                return pos.at(lhs) < pos.at(rhs);
            }
            if (pl || pr) {
                return !!pos.count(lhs);
            }
            return lhs < rhs;
        });
        return arr1;
    }
};

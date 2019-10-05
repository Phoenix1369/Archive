const int MAXA = 2005;
int cnt[MAXA];

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        for (int i = 0; i < MAXA; ++i) cnt[i] = 0;
        vector<int> ret;
        for (auto i: arr1) ++cnt[i];
        for (auto i: arr2) ++cnt[i];
        for (auto i: arr3) ++cnt[i];
        for (int i = 0; i < MAXA; ++i) {
            if (cnt[i] == 3) ret.push_back(i);
        }
        return ret;
    }
};

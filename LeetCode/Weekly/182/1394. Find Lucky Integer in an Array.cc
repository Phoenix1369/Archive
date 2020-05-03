const int MAXA = 501;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int cnt[MAXA]{ };
        for (int x: arr) ++cnt[x];
        for (int i = MAXA-1; i >= 1; --i) {
            if (cnt[i] == i) {
                return i;
            }
        }
        return -1;
    }
};

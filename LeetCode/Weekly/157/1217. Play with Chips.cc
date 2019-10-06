class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int cnt[2]{ };
        for (auto num: chips) {
            ++cnt[num & 1];
        }
        return *min_element(cnt, cnt + 2);
    }
};

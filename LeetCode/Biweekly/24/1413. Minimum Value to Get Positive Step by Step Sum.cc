class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int ret = 0;
        for (int x: nums) {
            sum += x;
            ret = min(sum, ret);
        }
        return (1 - ret);
    }
};

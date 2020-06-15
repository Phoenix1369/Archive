class Solution {
public:
    void sortColors(vector<int>& nums) {
        int N = nums.size();
        int zer = 0;
        int two = N-1;
        for (int i = 0; i <= two; ++i) {
            if (nums[i] == 2) {
                while ((two >= 0) && (nums[two] == 2)) --two;
                if (i > two) {
                    break;
                }
                swap(nums[i], nums[two--]);
                if (!nums[i]) --i;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[zer++]);
            }
        }
    }
};

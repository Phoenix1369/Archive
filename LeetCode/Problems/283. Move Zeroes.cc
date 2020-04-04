template <typename T>
using vec = vector<T>;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // copy_array_sol(nums);
        in_place_sol(nums);
    }

private:
    void copy_array_sol(vec<int>& nums) {
        int zero = 0;
        vec<int> ret;
        for (int& num: nums) {
            if (num) {
                ret.push_back(num);
            } else {
                ++zero;
            }
        }
        while (zero) {
            ret.push_back(0);
            --zero;
        }
        swap(nums, ret);
    }
    
    void in_place_sol(vec<int>& nums) {
        int N = nums.size();
        int live = 0;
        for (int i = 0; i < N; ++i) {
            if (nums[i]) {
                swap(nums[i], nums[live++]);
            }
        }
    }
};

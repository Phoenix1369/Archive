#define ALL(x) (x).begin(), (x).end()

template <typename T>
using vec = vector<T>;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (negative(nums)) {
            return *max_element(ALL(nums));
        }
        // return linear_sol(nums);
        return divide_and_conquer_sol(nums);
    }

private:
    int dfs(vec<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }
        int m = (l + r) / 2;
        int lhs = dfs(nums, l, m);
        int rhs = dfs(nums, m+1, r);
        
        int L = 0;
        for (int i = m, sum = 0; i >= l; --i) {
            sum += nums[i];
            L = max(sum, L);
        }
        
        int R = 0;
        for (int j = m+1, sum = 0; j <= r; ++j) {
            sum += nums[j];
            R = max(sum, R);
        }
        
        int cur = L + R;
        int val = max(lhs, rhs);
        return max(val, cur);
    }
    
    int divide_and_conquer_sol(vec<int>& nums) {
        int N = nums.size();
        return dfs(nums, 0, N-1);
    }
    
    int linear_sol(vec<int>& nums) {
        int sum = 0;
        int best = 0;
        for (int& num: nums) {
            sum += num;
            if (sum < 0) sum = 0;
            best = max(sum, best);
        }
        return best;
    }
    
    bool negative(vec<int>& nums) {
        return all_of(ALL(nums), [](int i) { return i < 0; });
    }
};

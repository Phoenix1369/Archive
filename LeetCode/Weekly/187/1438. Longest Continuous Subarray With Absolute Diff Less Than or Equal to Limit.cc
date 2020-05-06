const int MAXA = 1e9+5;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int N = nums.size();
        deque<int> mx;
        deque<int> mn;
        int mxp = -1;
        int mnp = -1;
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            while (!mx.empty() && (nums[mx.back()] < nums[i])) mx.pop_back();
            while (!mn.empty() && (nums[mn.back()] > nums[i])) mn.pop_back();
            mx.push_back(i);
            mn.push_back(i);
            
            while (!mx.empty() && !mn.empty()) {
                if (nums[mx.front()] - nums[mn.front()] <= limit) break;
                if (mx.front() < mn.front()) {
                    mxp = mx.front();
                    mx.pop_front();
                } else {
                    mnp = mn.front();
                    mn.pop_front();
                }
            }
            int len = i - max(mxp, mnp);
            ret = max(len, ret);
        }
        return ret;
    }
};

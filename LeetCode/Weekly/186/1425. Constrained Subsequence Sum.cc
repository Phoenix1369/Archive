const int MAXA = 1e4+5;
const int MAXN = 1e5+5;
int A[MAXN];
int dp[MAXN];
int N;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        N = nums.size();
        A[0] = 0;
        for (int i = 1; i <= N; ++i) {
            A[i] = A[i-1] + nums[i-1];
        }
        int ret = -MAXA;
        deque<int> Q;
        for (int i = 1; i <= N; ++i) {
            while (!Q.empty() &&
                   ((Q.front() + k < i) || (dp[Q.front()] < 0))) {
                Q.pop_front();
            }
            dp[i] = nums[i-1];
            if (!Q.empty()) {
                dp[i] += dp[Q.front()];
            }
            ret = max(dp[i], ret);
            while (!Q.empty() && (dp[Q.back()] < dp[i])) {
                Q.pop_back();
            }
            Q.push_back(i);
        }
        return ret;
    }
};

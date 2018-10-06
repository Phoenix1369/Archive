class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (int)nums.size();
        int sum = 0;
        for (const int& p: nums) {
            sum += p;
        }
        return n*(n+1)/2 - sum;
    }   // Consider overflow
};

const int K = 3;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int N = nums.size();
        int bit[K]{ };
        for (int x: nums) {
            bit[2] |= (bit[1] & x);
            bit[1] ^= x;
            bit[0] = (bit[1] & bit[2]);
            bit[1] &= ~bit[0];
            bit[2] &= ~bit[0];
        }
        return bit[1];
    }
};

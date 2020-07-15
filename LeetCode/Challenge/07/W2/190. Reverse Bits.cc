class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int lo = 0;
        int hi = 31;
        for (int lo = 0, hi = 31; lo < hi; ++lo, --hi) {
            int a = (n >> lo) & 1;
            int b = (n >> hi) & 1;
            if (a ^ b) {
                n ^= (1u << lo);
                n ^= (1u << hi);
            }
        }
        return n;
    }
};

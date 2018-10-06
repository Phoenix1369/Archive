class Solution {
public:
    int hammingWeight(uint32_t n) {
        int hamming = 0;
        while (n) {
            if (n & 1) {
                ++hamming;
            }
            n >>= 1;
        }
        return hamming;
    }
};

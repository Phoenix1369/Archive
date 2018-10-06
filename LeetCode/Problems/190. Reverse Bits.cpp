class Solution {
    const int LOGN = 32;

public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;

        for (int i = 0; i < LOGN; ++i) {
            m = (m << 1) | (n & 1);
            n = (n >> 1);
        }
        return m;
    }
};

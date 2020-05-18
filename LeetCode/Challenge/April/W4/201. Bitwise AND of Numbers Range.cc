class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (!m || !n) {
            return 0;
        }
        int m2 = bitlog2(m);
        int n2 = bitlog2(n);
        if (m2 != n2) {
            return 0;
        }
        int M = m & ~(1 << (m2 - 1));
        int N = n & ~(1 << (n2 - 1));
        return (1 << (m2 - 1)) | rangeBitwiseAnd(M, N);
    }

private:
    int bitlog2(int x) {
        int cnt = 0;
        while (x) {
            x >>= 1;
            ++cnt;
        }
        return cnt;
    }
};

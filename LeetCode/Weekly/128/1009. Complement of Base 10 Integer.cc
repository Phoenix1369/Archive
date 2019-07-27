class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) {
            return 1;
        }
        int two = 1;
        while (two <= N) two <<= 1;
        return ~N & (two - 1);
    }
};

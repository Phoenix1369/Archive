class Solution {
    int flips, ret;
public:
    int minKBitFlips(vector<int>& A, int K) {
        std::queue<int> cache;
        int N = A.size();
        flips = ret = 0;
        for (int i = 0; i < N; ++i) {
            if (!cache.empty() && cache.front() == i) {
                cache.pop();
                --flips;
            }
            if ((A[i] ^ (flips & 1)) == 0) {
                if (i+K > N) {
                    return -1;
                }
                cache.push(i+K);
                ++flips;
                ++ret;
            }
        }
        return ret;
    }
};

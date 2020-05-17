#define CLR(x) memset((x), 0, sizeof(x))
const int MAXA = 1<<16;
int cnt[MAXA];
int dnt[MAXA];

// 3SUM

class Solution {
public:
    int countTriplets(vector<int>& A) {
        CLR(cnt);
        CLR(dnt);
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ++dnt[A[i] & A[j]];
            }
        }
        int ret = 0;
        for (int x: A) {
            for (int k = 0; k < MAXA; ++k) {
                if ((x & k) == 0) {
                    ret += dnt[k];
                }
            }
        }
        return ret;
    }
};

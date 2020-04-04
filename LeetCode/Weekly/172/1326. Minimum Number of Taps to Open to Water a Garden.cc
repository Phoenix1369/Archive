#define ALL(x) (x).begin(), (x).end()

struct Pair {
    int L, R;
};

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<Pair> A;
        for (int i = 0; i <= n; ++i) {
            A.push_back({
                max(0, i - ranges[i]),
                min(n, i + ranges[i])
            });
        }
        sort(ALL(A), [](const Pair& l, const Pair& r) {
            return l.L < r.L;
        });
        int m = A.size();
        
        int end = 0;
        int ret = 0;
        for (int i = 1, j = 0; i <= n; ++i) {
            while ((j < m) && (A[j].L < i)) {
                end = max(A[j].R, end);
                ++j;
            }
            if (end < i) {
                return -1;
            }
            i = end;
            ++ret;
        }
        return ret;
    }
};

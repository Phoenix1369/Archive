#define ALL(x) (x).begin(), (x).end()

template <typename T>
using vec = vector<T>;
vec<vec<int>> A;
vec<vec<int>> B;

class Solution {
public:
    vector<int> minAvailableDuration(
            vector<vector<int>>& slots1,
            vector<vector<int>>& slots2,
            int duration
    ) {
        A = move(slots1);
        B = move(slots2);
        int N = A.size();
        int M = B.size();
        sort(ALL(A));
        sort(ALL(B));
        for (int i=0, j=0; (i < N) && (j < M); ++i) {
            while ((j < M) && (B[j][1] < A[i][0])) ++j;
            if (j >= M) break;
            if (B[j][0] > A[i][1]) continue;
            
            int head = max(A[i][0], B[j][0]);
            int tail = min(A[i][1], B[j][1]);
            if (tail - head >= duration) {
                return {head, head + duration};
            }
            if (A[i][1] >= B[j][1]) {
                --i;
                ++j;
            }
        }
        return {};
    }
};

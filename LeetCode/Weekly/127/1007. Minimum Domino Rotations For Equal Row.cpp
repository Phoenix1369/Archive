const int MAXD = 6;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int N = A.size();
        for (int& a: A) --a;
        for (int& b: B) --b;
        int yes = (1 << A[0]) | (1 << B[0]);
        for (int i = 0; i < N; ++i) {
            yes &= (1 << A[i]) | (1 << B[i]);
        }
        if (!yes) {
            return -1;
        }
        int ret = N;
        for (int j = 0; j < MAXD; ++j) if ((yes >> j) & 1) {
            int cnt[2]{ };
            for (int i = 0; i < N; ++i) {
                if (A[i] != j) ++cnt[0];
                if (B[i] != j) ++cnt[1];
            }
            ret = min(*min_element(cnt, cnt+2), ret);
        }
        return ret;
    }
};

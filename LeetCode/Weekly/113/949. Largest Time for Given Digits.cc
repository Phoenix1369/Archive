#define ALL(x) (x).begin(), (x).end()
const int BASE = 10;
char out[10];
int T[2];

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(ALL(A));
        T[0] = -1;
        do {
            int H = A[0] * BASE + A[1];
            if (H >= 24) continue;
            int M = A[2] * BASE + A[3];
            if (M >= 60) continue;
            T[0] = H;
            T[1] = M;
        } while (next_permutation(ALL(A)));
        if (T[0] >= 0) {
            sprintf(out, "%02d:%02d", T[0], T[1]);
        } else {
            out[0] = '\0';
        }
        return out;
    }
};

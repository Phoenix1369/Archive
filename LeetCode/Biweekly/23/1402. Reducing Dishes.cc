#define ALL(x) (x).begin(), (x).end()
const int MAXN = 505;
int P[MAXN];
int N;

class Solution {
public:
    int maxSatisfaction(vector<int>& S) {
        N = S.size();
        sort(ALL(S));
        int sum = 0;
        P[N] = 0;
        for (int i = N-1; i >= 0; --i) {
            P[i] = P[i+1] + S[i];
            sum +=  (i+1) * S[i];
        }
        int ret = sum;
        for (int i = 0; i < N; ++i) {
            sum -= P[i];
            ret = max(sum, ret);
        }
        return ret;
    }
};

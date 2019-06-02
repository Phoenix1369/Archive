#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(ALL(tokens));
        int N = tokens.size();
        int lo = 0;
        int hi = N-1;
        int pts = 0;
        int ret = 0;
        while (lo <= hi) {
            if (P >= tokens[lo]) {
                P -= tokens[lo];
                ++pts;
                ret = max(pts, ret);
                ++lo;
            } else if (pts > 0) {
                --pts;
                P += tokens[hi];
                --hi;
            } else {
                lo = hi + 1;
            }
        }
        return ret;
    }
};

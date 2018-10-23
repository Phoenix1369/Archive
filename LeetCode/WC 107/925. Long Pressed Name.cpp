class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int N = (int)name.size();
        int T = (int)typed.size();
        int n=0, t=0;
        while (t < T) {
            if (n == N) {
                return true;
            }
            int nn = n+1;
            int tt = t+1;
            while ((nn < N) && (name[nn] == name[n])) {
                ++nn;
            }
            while ((tt < T) && (typed[tt]== typed[t])) {
                ++tt;
            }
            if ((tt-t) < (nn-n)) {
                return false;
            }
            n = nn;
            t = tt;
        }
        return (n == N);
    }
};

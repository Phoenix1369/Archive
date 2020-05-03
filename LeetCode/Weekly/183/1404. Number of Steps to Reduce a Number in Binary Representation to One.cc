#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    int numSteps(string s) {
        int N = s.size();
        int ret = 0;
        for (int i = N-1; i >= 0; --i) {
            if (s[i] == '0') {
                ++ret;
                continue;
            }
            if (!i) break;
            
            ++ret;
            while ((i >= 0) && (s[i] == '1')) {
                ++ret;
                --i;
            }
            if (i >= 0) s[i++] = '1';
        }
        return ret;
    }
};

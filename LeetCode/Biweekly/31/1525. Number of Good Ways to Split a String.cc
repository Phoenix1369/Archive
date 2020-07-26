const int MAXA = 26;

template <typename T>
using vec = vector<T>;

vec<vec<int>> suf;
vec<int> cur;

class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        cur.assign(MAXA, 0);
        suf.assign(n, cur);
        for (int i = n-2; i >= 0; --i) {
            ++suf[i][s[i+1]-'a'];
            for (int j = 0; j < MAXA; ++j) {
                suf[i][j] += suf[i+1][j];
            }
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ++cur[s[i]-'a'];
            int c = 0;
            int s = 0;
            for (int j = 0; j < MAXA; ++j) {
                if (cur[j]) ++c;
                if (suf[i][j]) ++s;
            }
            if (c == s) {
                ++ret;
            }
        }
        return ret;
    }
};

const int MAXA = 26;

class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[MAXA]{ };
        for (char c: s) ++cnt[c-'a'];
        
        int dnt[MAXA]{ };
        for (char d: t) ++dnt[d-'a'];
        
        int ret = 0;
        for (int i = 0; i < MAXA; ++i) {
            ret += abs(cnt[i] - dnt[i]);
        }
        ret /= 2;
        return ret;
    }
};

const int MAXA = 26;

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int N = s1.size();
        int cnt[MAXA]{ };
        int dnt[MAXA]{ };
        for (char c: s1) ++cnt[c-'a'];
        for (char d: s2) ++dnt[d-'a'];
        for (int i = 1; i < MAXA; ++i) {
            cnt[i] += cnt[i-1];
            dnt[i] += dnt[i-1];
        }
        bool b1 = true;
        bool b2 = true;
        for (int i = 0; i < MAXA; ++i) {
            b1 &= (cnt[i] >= dnt[i]);
            b2 &= (dnt[i] >= cnt[i]);
        }
        return (b1 || b2);
    }
};

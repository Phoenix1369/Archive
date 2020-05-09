const int MAXA = 26;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[MAXA]{ };
        int dnt[MAXA]{ };
        for (char c: ransomNote) ++cnt[c-'a'];
        for (char d: magazine) ++dnt[d-'a'];
        for (int i = 0; i < MAXA; ++i) {
            if (cnt[i] > dnt[i]) {
                return false;
            }
        }
        return true;
    }
};

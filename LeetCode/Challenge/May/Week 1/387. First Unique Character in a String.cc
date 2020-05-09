const int MAXA = 26;

class Solution {
public:
    int firstUniqChar(string s) {
        int N = s.size();
        int cnt[MAXA]{ };
        for (char c: s) ++cnt[c-'a'];
        for (int i = 0; i < N; ++i) {
            if (cnt[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

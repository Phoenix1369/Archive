const int MAXA = 26;
int pos[MAXA];

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        for (int i = 0; i < MAXA; ++i) {
            pos[keyboard[i]-'a'] = i;
        }
        int cur = 0;
        int ret = 0;
        for (auto c: word) {
            ret += abs(pos[c-'a'] - cur);
            cur = pos[c-'a'];
        }
        return ret;
    }
};

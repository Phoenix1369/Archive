const int MAXN = 505;
char T[MAXN];

class Solution {
public:
    string reformat(string s) {
        int cnt[2]{ };
        for (char c: s) ++cnt[c >= 'a'];
        if (abs(cnt[0] - cnt[1]) > 1) {
            return "";
        }
        int pos[2] = {0, 1};
        int idx = (cnt[0] < cnt[1]) ? 1 : 0;
        for (char c: s) {
            int k = idx ^ (c >= 'a');
            T[pos[k]] = c;
            pos[k] += 2;
        }
        T[s.size()] = '\0';
        return T;
    }
};

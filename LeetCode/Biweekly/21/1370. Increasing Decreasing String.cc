const int MAXA = 26;
const int MAXN = 505;
char T[MAXN];

class Solution {
public:
    string sortString(string s) {
        int cnt[MAXA]{ };
        for (char c: s) ++cnt[c-'a'];
        int N = s.size();
        int K = 0;
        while (N) {
            for (int i = 0; i < MAXA; ++i) if (cnt[i]) {
                T[K++] = 'a'+i;
                --cnt[i];
                --N;
            }
            for (int i = MAXA-1; i >= 0; --i) if (cnt[i]) {
                T[K++] = 'a'+i;
                --cnt[i];
                --N;
            }
        }
        T[K] = '\0';
        return T;
    }
};

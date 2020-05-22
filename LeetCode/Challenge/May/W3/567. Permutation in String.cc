const int MAXA = 26;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int N = s1.size();
        int M = s2.size();
        int cnt[MAXA]{ };
        int dnt[MAXA]{ };
        for (char c: s1) ++cnt[c-'a'];
        for (int i = 0; i < M; ++i) {
            ++dnt[s2[i]-'a'];
            if (i >= N) --dnt[s2[i-N]-'a'];
            if (i < N-1) continue;
            bool valid = true;
            for (int j = 0; j < MAXA; ++j) {
                if (dnt[j] != cnt[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                return true;
            }
        }
        return false;
    }
};

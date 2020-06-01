const int MAXA = 26;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int N = s.size();
        int M = p.size();
        int pnt[MAXA]{ };
        int snt[MAXA]{ };
        vector<int> ret;
        for (char c: p) ++pnt[c-'a'];
        for (int i = 0; i < N; ++i) {
            ++snt[s[i]-'a'];
            if (i >= M) --snt[s[i-M]-'a'];
            if (i < M-1) continue;
            bool valid = true;
            for (int j = 0; j < MAXA; ++j) {
                if (snt[j] != pnt[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ret.push_back(i-M+1);
            }
        }
        return ret;
    }
};

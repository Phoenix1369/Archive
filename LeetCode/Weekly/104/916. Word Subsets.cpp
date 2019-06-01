const int MAXA = 26;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int bnt[MAXA]{ };
        for (const string& s: B) {
            int cnt[MAXA]{ };
            for (const char& c: s) {
                ++cnt[c-'a'];
            }
            for (int i = 0; i < MAXA; ++i) {
                bnt[i] = max(cnt[i], bnt[i]);
            }
        }
        vector<string> ret;
        for (const string& s: A) {
            int cnt[MAXA]{ };
            for (const char& c: s) {
                ++cnt[c-'a'];
            }
            bool yes = true;
            for (int i = 0; i < MAXA; ++i) {
                yes &= (cnt[i] >= bnt[i]);
            }
            if (yes) ret.push_back(s);
        }
        return ret;
    }
};

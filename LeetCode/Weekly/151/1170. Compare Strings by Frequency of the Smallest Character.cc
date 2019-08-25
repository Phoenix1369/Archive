const int MAXC = 15;
int cnt[MAXC];

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        for (int i = 0; i < MAXC; ++i) cnt[i] = 0;
        for (auto w: words) {
            ++cnt[f(w)];
        }
        for (int i = MAXC-2; i >= 0; --i) {
            cnt[i] += cnt[i+1];
        }
        vector<int> ret;
        for (auto q: queries) {
            ret.push_back(cnt[f(q) + 1]);
        }
        return ret;
    }

private:
    int f(const string& s) {
        char a = 'z';
        for (char c: s) a = min(c, a);
        int ret = 0;
        for (char c: s) if (c == a) ++ret;
        return ret;
    }
};

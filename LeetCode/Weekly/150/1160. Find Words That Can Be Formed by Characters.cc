const int MAXA = 26;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[MAXA]{ };
        int N = chars.size();
        for (int i = 0; i < N; ++i) {
            ++cnt[chars[i]-'a'];
        }
        int ret = 0;
        for (auto w: words) {
            int M = w.size();
            int dnt[MAXA]{ };
            for (int j = 0; j < M; ++j) {
                ++dnt[w[j]-'a'];
            }
            if (good(dnt, cnt)) {
                ret += M;
            }
        }
        return ret;
    }

private:
    bool good(int* dnt, int* cnt) {
        for (int i = 0; i < MAXA; ++i) {
            if (dnt[i] > cnt[i]) return false;
        }
        return true;
    }
};

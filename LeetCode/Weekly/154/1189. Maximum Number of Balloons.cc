const string BALL = "balloon";
const int MAXA = 26;
int cnt[MAXA];
int dnt[MAXA];

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        init();
        for (char c: text) {
            ++dnt[c-'a'];
        }
        int ret = text.size();
        for (int i = 0; i < MAXA; ++i) {
            if (!cnt[i]) continue;
            ret = min(dnt[i] / cnt[i], ret);
        }
        return ret;
    }

private:
    void init() {
        for (int i = 0; i < MAXA; ++i) {
            cnt[i] = dnt[i] = 0;
        }
        for (char c: BALL) {
            ++cnt[c-'a'];
        }
    }
};

const int MAXN = 1e4+5;
int cnt[MAXN];

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        for (int i = 0; i < MAXN; ++i) {
            cnt[i] = 0;
        }
        for (auto d: deck) {
            ++cnt[d];
        }
        int g = 0;
        for (int i = 0; i < MAXN; ++i) {
            g = gcd(cnt[i], g);
        }
        return (g != 1);
    }
};


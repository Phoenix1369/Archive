#define ALL(x) (x).begin(), (x).end()
const int MAXN = 3e4+5;
unordered_map<int,int> cnt;

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        init();
        sort(ALL(A), [](int a, int b) {
            return abs(a) < abs(b);
        });
        for (int x: A) ++cnt[x];
        for (int x: A) {
            if (!cnt.count(x)) continue;
            int y = x*2;
            if (!cnt.count(y)) {
                return false;
            }
            if (!--cnt[x]) cnt.erase(x);
            if (!--cnt[y]) cnt.erase(y);
        }
        return true;
    }

private:
    void init() {
        cnt.clear();
        cnt.reserve(MAXN);
    }
};

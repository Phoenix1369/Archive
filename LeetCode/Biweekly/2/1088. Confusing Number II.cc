#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
const int BASE = 10;
const int MAXD = 5;
const unordered_map<int,int> R = {{0,0}, {1,1}, {6,9}, {8,8}, {9,6}};

class Solution {
    int N, ret;

public:
    int confusingNumberII(int n) {
        N = n;
        ret = 0;
        for (auto itr: R) {
            int num = itr.first;
            if (num) dfs(num);
        }
        return ret;
    }

private:
    void dfs(int num) {
        if (is_confusing(num)) {
            ++ret;
        }
        for (auto itr: R) {
            lld nxt = 1LL * BASE * num + itr.first;
            if (nxt > N) continue;
            dfs(nxt);
        }
    }

    bool is_confusing(const int n) {
        int m = n;
        lld r = 0LL;
        while (m) {
            int rem = m % BASE;
            r = 1LL * BASE * r + R.at(rem);
            m /= BASE;
        }
        return (n != r);
    }
};

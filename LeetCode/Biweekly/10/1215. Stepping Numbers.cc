#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
const int BASE = 10;

class Solution {
    vector<int> ret;
    int hi, lo;
    
public:
    vector<int> countSteppingNumbers(int low, int high) {
        hi = high;
        lo = low;
        for (int i = 0; i < BASE; ++i) {
            dfs(i);
        }
        sort(ALL(ret));
        return ret;
    }

private:
    void dfs(int cur) {
        int pre = cur % BASE;
        if (lo <= cur) {
            ret.push_back(cur);
        }
        if (!cur) {
            return;
        }   // Skip Leading Zero.
        for (int dx = -1; dx <= 1; dx += 2) {
            int sum = pre + dx;
            if (!in_range(sum)) {
                continue;
            }
            lld nxt = 1LL * BASE * cur + sum;
            if (nxt <= hi) {
                dfs(nxt);
            }
        }
    }
    
    bool in_range(int n) {
        return (0 <= n) && (n < BASE);
    }
};

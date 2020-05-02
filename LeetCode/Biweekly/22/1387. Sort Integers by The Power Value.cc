const int MAXC = 2228;
const int MAXK = 1001;
unordered_map<int,int> cache;
int A[MAXK];

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        if (cache.empty()) {
            init();
        }
        int n = hi - lo + 1;
        for (int i = 0; i < n; ++i) {
            A[i] = lo + i;
        }
        sort(A, A+n, [](int lhs, int rhs) {
            int pl = cache.at(lhs);
            int pr = cache.at(rhs);
            return (pl != pr)
                ? (pl < pr)
                : (lhs < rhs);
        });
        return A[k-1];
    }

private:
    int dfs(int x) {
        if (cache.count(x)) {
            return cache.at(x);
        }
        return cache[x] = 1 + ((x & 1)
            ? dfs(3 * x + 1)
            : dfs(x / 2));
    }
    
    void init() {
        cache.reserve(MAXC);
        cache[1] = 0;
        for (int i = 1; i < MAXK; ++i) {
            dfs(i);
        }
    }
};

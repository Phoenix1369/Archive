const int MAXA = 1e5+1;
const int SQTA = 317;

int cnt[MAXA];
int par[MAXA];
vector<int> F;

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        init();
        for (int x: A) {
            int K = factor(x);
            for (int i = 1; i < K; ++i) {
                unite(F[i-1], F[i]);
            }
            if (!F.empty()) {
                add(F.front());
            }
        }
        return solve();
    }

private:
    void init() {
        for (int i = 0; i < MAXA; ++i) {
            cnt[i] = 0;
            par[i] = i;
        }
    }
    
    int factor(int x) {
        F.clear();
        for (int i = 2; i < SQTA; ++i) {
            if (x % i) continue;
            while ((x % i) == 0) x /= i;
            F.push_back(i);
        }
        if (x > 1) {
            F.push_back(x);
        }
        return F.size();
    }
    
    int solve() {
        int ret = 0;
        for (int i = 0; i < MAXA; ++i) {
            ret = max(cnt[i], ret);
        }
        return ret;
    }
    
    // Union-Find Disjoint-Set
    void add(int u) {
        ++cnt[find(u)];
    }
    
    int find(int u) {
        int v = u;
        while (par[v] != v) v = par[v];
        while (u != v) {
            int w = par[u];
            par[u] = v;
            u = w;
        }
        return v;
    }
    
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            par[a] = b;
            cnt[b] += cnt[a];
        }
    }
};

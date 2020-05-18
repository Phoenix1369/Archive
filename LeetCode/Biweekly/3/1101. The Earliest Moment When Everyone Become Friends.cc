#define ALL(x) (x).begin(), (x).end()
const int MAXN = 105;
int dsu[MAXN];
int len[MAXN];
int N;

class Solution {
public:
    int earliestAcq(vector<vector<int>> logs, int n) {
        N = n;
        init();
        sort(ALL(logs), [](const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0];
        });
        for (auto log: logs) {
            int t = log[0];
            int a = log[1];
            int b = log[2];
            if (unite(a, b)) {
                return t;
            }
        }
        return -1;
    }

private:
    void init() {
        for (int i = 0; i < N; ++i) {
            dsu[i] = i;
            len[i] = 1;
        }
    }
    
    int find(int u) {
        int v = u;
        while (v != dsu[v]) v = dsu[v];
        while (u != v) {
            int tmp = dsu[u];
            dsu[u] = v;
            u = tmp;
        }
        return u;
    }
    
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            dsu[a] = b;
            len[b] += len[a];
        }
        return (len[dsu[a]] == N);
    }
};

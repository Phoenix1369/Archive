#define ALL(x) (x).begin(), (x).end()

class Solution {
    const static int MAXN = 26;
    std::set<int> dsu[MAXN];
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < MAXN; ++i) {
            dsu[i].clear();
            dsu[i].insert(i);
        }
        for (const auto& eqn: equations) if (eqn[1] == '=') {
            unite(eqn[0]-'a', eqn[3]-'a');
        }
        for (const auto& eqn: equations) if (eqn[1] == '!') {
            for (int i = 0; i < MAXN; ++i) {
				if (dsu[i].count(eqn[0]-'a') &&
					dsu[i].count(eqn[3]-'a')) {
                    return false;
                }
            }
        }
        return true;
    }
    
    int find(int p) {
        for (int i = 0; i < MAXN; ++i) if (dsu[i].count(p)) {
            return i;
        }
        return p;
    }
    
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (dsu[u].size() < dsu[v].size()) {
            dsu[v].insert(ALL(dsu[u]));
            dsu[u].clear();
        } else {
            dsu[u].insert(ALL(dsu[v]));
            dsu[v].clear();
        }
    }
};

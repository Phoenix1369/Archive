const int MAXN = 5005;
int deg[MAXN], lvl[MAXN];
vector<int> G[MAXN];

class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        for (int i = 1; i <= N; ++i) {
            deg[i] = lvl[i] = 0;
            G[i].clear();
        }
        for (auto e: relations) {
            // reverse: e[0] <- e[1]
            ++deg[e[0]];
            G[e[1]].push_back(e[0]);
        }
        int ret = -1;
        queue<int> Q;
        for (int i = 1; i <= N; ++i) {
            if (deg[i] == 0) {
                lvl[i] = 1;
                ret = max(lvl[i], ret);
                Q.push(i);
            }
        }
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for (auto nxt: G[cur]) {
                if (!--deg[nxt]) {
                    lvl[nxt] = lvl[cur] + 1;
                    ret = max(lvl[nxt], ret);
                    Q.push(nxt);
                }
            }
        }
        for (int i = 1; i <= N; ++i) {
            if (!lvl[i]) {
                return -1;
            }
        }
        return ret;
    }
};

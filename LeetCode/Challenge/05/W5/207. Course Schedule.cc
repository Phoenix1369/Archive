const int MAXN = 1e5+5;
vector<int> G[MAXN];
int deg[MAXN];
int N;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        N = numCourses;
        init();
        for (auto& e: prerequisites) {
            int u = e[0];
            int v = e[1];
            G[v].push_back(u);
            ++deg[u];
        }
        queue<int> Q;
        for (int i = 0; i < N; ++i) {
            if (!deg[i]) Q.push(i);
        }
        int done = 0;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            ++done;
            for (int v: G[u]) {
                if (!--deg[v]) Q.push(v);
            }
        }
        return (done == N);
    }

private:
    void init() {
        for (int i = 0; i < N; ++i) {
            deg[i] = 0;
            G[i].clear();
        }
    }
};

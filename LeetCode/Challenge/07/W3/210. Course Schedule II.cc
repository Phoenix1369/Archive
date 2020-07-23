template <typename T>
using vec = vector<T>;

vec<vec<int>> G;
vec<int> deg;
unsigned N;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        N = numCourses;
        G.assign(N, vec<int>());
        deg.assign(N, 0);
        for (const auto& edge: prerequisites) {
            int u = edge[0];
            int v = edge[1];
            G[v].push_back(u);
            ++deg[u];
        }
        queue<int> Q;
        for (int i = 0; i < N; ++i) {
            if (!deg[i]) {
                Q.push(i);
            }
        }
        vec<int> ret;
        while (!Q.empty()) {
            int u = Q.front();
            ret.push_back(u);
            Q.pop();
            for (auto v: G[u]) {
                if (!--deg[v]) {
                    Q.push(v);
                }
            }
        }
        return (ret.size() == N) ? ret : vec<int>();
    }
};

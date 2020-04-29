template <typename T>
using vec = vector<T>;

const int MAXN = 5e4+5;
unordered_map<int, vec<int>> C;
int D[MAXN];
vec<int> A;
int K, N;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        A = move(arr);
        N = A.size();
        init();
        for (int i = 0; i < N; ++i) {
            C[A[i]].push_back(i);
        }
        bfs(0);
        return D[N-1];
    }

private:
    void bfs(int src) {
        queue<int> Q;
        Q.push(src);
        D[src] = 0;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int du = -1; du <= 1; du += 2) {
                int v = u + du;
                if (v < 0) continue;
                if (D[v] != -1) continue;
                D[v] = D[u] + 1;
                Q.push(v);
            }
            for (int v: C[A[u]]) {
                if (D[v] != -1) continue;
                D[v] = D[u] + 1;
                Q.push(v);
            }
            C[A[u]].clear();
        }
    }
    
    void init() {
        K = 0;
        C.clear();
        C.reserve(N);
        for (int i = 0; i < N; ++i) {
            D[i] = -1;
        }
    }
};

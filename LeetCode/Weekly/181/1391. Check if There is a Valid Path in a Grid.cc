template <typename T>
using vec = vector<T>;

const int MAXK = 4;
const int MAXN = 305;
const int dir[MAXK][MAXK] = {
    {0, 6, 2, 5},
    {6, 0, 4, 1},
    {2, 4, 0, 3},
    {5, 1, 3, 0}
};  // NESW
const int moves[MAXK][2] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};  // NESW
bool V[MAXN][MAXN][MAXK];
int M, N;

struct State {
    int r, c, d;
    
    bool in_range() const {
        return (0 <= r) && (r < N) && (0 <= c) && (c < M);
    }
    
    bool& seen() const { return V[r][c][d]; }
};
vec<vec<int>> G;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        G = move(grid);
        N = G.size();
        M = G[0].size();
        init();
        return bfs({0, 0, 0});
    }

private:
    bool bfs(State src) {
        queue<State> Q;
        for (int k = 0; k < MAXK; ++k) {
            src.d = k;
            src.seen() = true;
            Q.push(src);
        }
        while (!Q.empty()) {
            State u = Q.front();
            Q.pop();
            
            int k = orient(u);
            // Invalid entry
            if (k == -1) continue;
            if ((u.r == N-1) && (u.c == M-1)) {
                return true;
            }
            
            State v = {
                u.r + moves[k][0],
                u.c + moves[k][1],
                (k + 2) % MAXK
            };
            if (!v.in_range() || v.seen()) continue;
            v.seen() = true;
            Q.push(v);
        }
        return false;
    }
    
    int orient(const State& u) {
        for (int k = 0; k < MAXK; ++k) {
            if (G[u.r][u.c] == dir[u.d][k]) {
                return k;
            }
        }
        return -1;
    }
    
    void init() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                for (int k = 0; k < MAXK; ++k) {
                    V[i][j][k] = false;
                }
            }
        }
    }
};

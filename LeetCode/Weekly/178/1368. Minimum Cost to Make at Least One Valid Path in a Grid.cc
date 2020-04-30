const int MAXD = 4;
const int MAXN = 105;
const int moves[][2] = {{0,0}, {0,1}, {0,-1}, {1,0}, {-1,0}}; // EWSN
int  A[MAXN][MAXN][MAXD];
bool V[MAXN][MAXN][MAXD];
int M, N;

struct State {
    int r, c, d;
    
    int&  dist() const { return A[r][c][d-1]; }
    bool& seen() const { return V[r][c][d-1]; }
    bool in_range() const {
        return (0 <= r) && (r < N) && (0 <= c) && (c < M);
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();
        init();
        State src{0, 0, grid[0][0]};
        
        queue<State> Q0;
        queue<State> Q1;
        Q0.push(src);
        src.dist() = 0;
        for (int k = 1; k <= MAXD; ++k) {
            if (k == src.d) continue;
            State cur = {0, 0, k};
            cur.dist() = 1;
            Q1.push(cur);
        }
        while (!Q0.empty()) {
            State cur = Q0.front();
            Q0.pop();
            if (cur.seen()) continue;
            cur.seen() = true;
            
            State nxt = cur;
            nxt.r += moves[cur.d][0];
            nxt.c += moves[cur.d][1];
            if (nxt.in_range()) {
                auto transit = [&nxt](queue<State>& Q, int cost) {
                    if (nxt.dist() <= cost) return;
                    nxt.dist() = cost;
                    Q.push(nxt);
                };
                for (nxt.d = 1; nxt.d <= MAXD; ++nxt.d) {
                    if (nxt.d != grid[nxt.r][nxt.c]) {
                        transit(Q1, cur.dist() + 1);
                    } else {
                        transit(Q0, cur.dist());
                    }
                }
            }
            if (Q0.empty()) {
                Q0.swap(Q1);
            }
        }
        const auto& dest = A[N-1][M-1];
        return *min_element(dest, dest + MAXD);
    }

private:
    void init() {
        int cost = N * M + 1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                for (int k = 0; k < MAXD; ++k) {
                    A[i][j][k] = cost;
                    V[i][j][k] = false;
                }
            }
        }
    }
};

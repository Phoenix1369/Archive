const int MAXA = 1e9+7;
const int MAXK = 4;
const int MAXN = 105;
const int dir[MAXK][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int D[MAXN][MAXN];
int C, R;

struct State {
    int w, r, c;
    
    bool operator < (const State& o) const {
        return o.w > w;
    }
    
    bool in_range() const {
        return (0 <= r) && (r < R) && (0 <= c) && (c < C);
    }
};

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>> A) {
        R = A.size();
        C = A[0].size();
        init();
        
        priority_queue<State> Q;
        Q.push({A[0][0], 0, 0});
        D[0][0] = A[0][0];
        while (!Q.empty()) {
            State cur = Q.top();
            Q.pop();
            if ((cur.r == R-1) && (cur.c == C-1)) {
                return D[cur.r][cur.c];
            }
            for (int k = 0; k < MAXK; ++k) {
                int nr = cur.r + dir[k][0];
                int nc = cur.c + dir[k][1];
                State nxt{0, nr, nc};
                if (!nxt.in_range()) continue;
                nxt.w = min(A[nr][nc], cur.w);
                if (D[nr][nc] > nxt.w) {
                    D[nr][nc] = nxt.w;
                    Q.emplace(move(nxt));
                }
            }
        }
        return 0;
    }

private:
    void init() {
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                D[i][j] = MAXA;
            }
        }
    }
};

const int INFN = 1e9+7;
const int MAXN = 20;
const int MOVE = 4;
const int moves[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int dp[MAXN][MAXN][MAXN][MAXN];
int M, N;

struct State {
    int sr, sc, br, bc, p;
    
    bool operator < (const State& o) const {
        return o.p < p;
    }
};

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        N = grid.size();
        M = grid[0].size();
        init();
        
        State src = {0,0,0,0,0};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 'S') {
                    src.sr = i;
                    src.sc = j;
                } else if (grid[i][j] == 'B') {
                    src.br = i;
                    src.bc = j;
                }
            }
        }
        get(src) = 0;
        
        int best = INFN;
        priority_queue<State> Q;
        Q.push(src);
        while (!Q.empty()) {
            State cur = Q.top();
            Q.pop();
            
            if (grid[cur.br][cur.bc] == 'T') {
                best = min(get(cur), best);
            }
            if (get(cur) < cur.p) {
                continue;
            }
            
            int cy = cur.sr;
            int cx = cur.sc;
            for (int k = 0; k < MOVE; ++k) {
                int ny = cy + moves[k][0];
                int nx = cx + moves[k][1];
                if (!in_range(ny, nx)) {
                    continue;
                }
                if (grid[ny][nx] == '#') {
                    continue;
                }
                
                int by = cur.br;
                int bx = cur.bc;
                int push = 0;
                if ((by == ny) && (bx == nx)) {
                    by += moves[k][0];
                    bx += moves[k][1];
                    ++push;
                }
                if (!in_range(by, bx)) {
                    continue;
                }
                if (grid[by][bx] == '#') {
                    continue;
                }
                
                State nxt = {ny,nx,by,bx,0};
                int cost = get(cur) + push;
                if (get(nxt) <= cost) {
                    continue;
                }
                get(nxt) = cost;
                nxt.p = cost;
                Q.push(nxt);
            }
        }
        if (best == INFN) {
            return -1;
        }
        return best;
    }

private:
    int& get(State& s) {
        return dp[s.sr][s.sc][s.br][s.bc];
    }
    
    bool in_range(int y, int x) {
        return (0 <= y) && (y < N) && (0 <= x) && (x < M);
    }
    
    void init() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                for (int k = 0; k < N; ++k) {
                    for (int l = 0; l < M; ++l) {
                        dp[i][j][k][l] = INFN;
                    }
                }
            }
        }
    }
};

/*
[["#","#","#","#","#","#"],["#","T","#","#","#","#"],["#",".",".","B",".","#"],["#",".","#","#",".","#"],["#",".",".",".","S","#"],["#","#","#","#","#","#"]]
[["#","#","#","#","#","#"], ["#","T","#","#","#","#"], ["#",".",".","B",".","#"], ["#","#","#","#",".","#"], ["#",".",".",".","S","#"],["#","#","#","#","#","#"]]
[["#","#","#","#","#","#"], ["#","T",".",".","#","#"], ["#",".","#","B",".","#"], ["#",".",".",".",".","#"], ["#",".",".",".","S","#"],  ["#","#","#","#","#","#"]]
[["#","#","#","#","#","#","#"], ["#","S","#",".","B","T","#"], ["#","#","#","#","#","#","#"]]
>> 3
>> -1
>> 5
>> -1
*/

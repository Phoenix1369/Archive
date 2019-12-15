const int MAXN = 45;
const int NOPE = -1;
const int moves[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int dp[MAXN][MAXN][MAXN*MAXN];
int K, M, N;

struct State {
    int y, x, r;
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        N = grid.size();
        M = grid[0].size();
        K = k;
        init();
        
        queue<State> Q;
        State cur = {0, 0, 0};
        get(cur) = 0;
        Q.push(cur);
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            if ((cur.y == N-1) && (cur.x == M-1)) {
                return get(cur);
            }
            for (int k = 0; k < 4; ++k) {
                State nxt = cur;
                nxt.y = cur.y + moves[k][0];
                nxt.x = cur.x + moves[k][1];
                if (!in_range(nxt)) {
                    continue;
                }
                nxt.r = cur.r;
                if (grid[nxt.y][nxt.x]) {
                    ++nxt.r;
                }
                if (nxt.r > K) {
                    continue;
                }
                if (get(nxt) != NOPE) {
                    continue;
                }
                get(nxt) = get(cur) + 1;
                Q.push(nxt);
            }
        }
        return NOPE;
    }

private:
    int& get(const State& s) {
        return dp[s.y][s.x][s.r];
    }
    
    bool in_range(const State& s) {
        return (0 <= s.y) && (s.y < N) && (0 <= s.x) && (s.x < M);
    }
    
    void init() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                for (int k = 0; k <= K; ++k) {
                    dp[i][j][k] = NOPE;
                }
            }
        }
    }
};

/*
[[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]]
1
[[0,1,1],[1,1,1],[1,0,0]]
1
>> 6
>> -1
*/

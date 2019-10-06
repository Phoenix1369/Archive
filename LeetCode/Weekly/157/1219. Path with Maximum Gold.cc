const vector<vector<int>> moves = {{0,-1}, {1,0}, {0,1}, {-1,0}};
vector<vector<int>> G;
int M, N;
int ret, sum;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        G = move(grid);
        N = G.size();
        M = G[0].size();
        return solve();
    }

private:
    void dfs(int row, int col) {
        for (auto d: moves) {
            int nr = row + d[0];
            int nc = col + d[1];
            if (inrange(nr, nc)) {
                enqueue(nr, nc);
            }
        }
        ret = max(sum, ret);
    }

    void enqueue(int r, int c) {
        if (!G[r][c]) return;
        int val = G[r][c];
        
        sum += val;
        G[r][c] = 0;
        
        dfs(r, c);
        
        G[r][c] = val;
        sum -= val;
    }

    bool inrange(int r, int c) {
        return (0 <= r) && (r < N) && (0 <= c) && (c < M);
    }

    int solve() {
        ret = 0;
        sum = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                enqueue(i, j);
            }
        }
        return ret;
    }
};

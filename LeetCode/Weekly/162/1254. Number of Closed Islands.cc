template <typename T>
using vin = vector<T>;
const int MAXK = 4;
const int MAXN = 105;
const int WATER = 1;
const int moves[MAXK][2] = {{-1,0},{0,1},{1,0}, {0,-1}};
bool seen[MAXN][MAXN];
vin<vin<int>> A;
int M, N;
bool closed;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        A = move(grid);
        N = A.size();
        M = A[0].size();
        init();
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (seen[i][j] || (A[i][j] == WATER)) {
                    continue;
                }
                closed = true;
                dfs(i, j);
                if (closed) {
                    ++ret;
                }
            }
        }
        return ret;
    }

private:
    void dfs(int r, int c) {
        seen[r][c] = true;
        for (int k = 0; k < MAXK; ++k) {
            int nr = r + moves[k][0];
            int nc = c + moves[k][1];
            if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= M)) {
                closed = false;
                continue;
            }
            if (seen[nr][nc] || (A[nr][nc] == WATER)) {
                continue;
            }
            dfs(nr, nc);
        }
    }

    void init() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                seen[i][j] = false;
            }
        }
    }
};

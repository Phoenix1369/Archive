#define CLR(x) memset((x), false, sizeof(x))
const int MAXK = 4;
const int MAXN = 35;
const int dir[MAXK][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}}; // NESW
const int rot[MAXK][2] = {{3,1}, {1,3}, {3,1}, {1,3}};  // CW or CCW
bool seen[MAXN][MAXN][MAXK];
vector<string> G;
int N;

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        G = move(grid);
        N = G.size();
        CLR(seen);
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < MAXK; ++k) {
                    if (seen[i][j][k]) continue;
                    dfs(i, j, k);
                    ++ret;
                }
            }
        }
        return ret;
    }

private:
    void dfs(int r, int c, int d) {
        if (seen[r][c][d]) {
            return;
        }
        seen[r][c][d] = true;
        
        if (G[r][c] == ' ') {
            return blank(r, c);
        }
        int pos = (G[r][c] == '/') ? 0 : 1;
        advance(r, c, d, dir[d][0], dir[d][1], 2);
        advance(r, c, d, 0, 0, rot[d][pos]);
    }
    
    void advance(int r, int c, int d, int dr, int dc, int dd) {
        int nr = r + dr;
        int nc = c + dc;
        if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= N)) return;
        int nd = (d + dd) % MAXK;
        dfs(nr, nc, nd);
    }
    
    void blank(int r, int c) {
        for (int k = 0; k < MAXK; ++k) {
            seen[r][c][k] = true;
        }
        for (int k = 0; k < MAXK; ++k) {
            advance(r, c, k, dir[k][0], dir[k][1], 2);
        }
    }
};

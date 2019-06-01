typedef vector<int> vin;
const int MAXN = 55;
int  prod[MAXN][MAXN];
bool seen[MAXN][MAXN];

class Solution {
    int moves[4][2] = {{0,-1},{+1,0},{0,+1},{-1,0}}; // NESW
    int C, R;

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        R = grid.size();
        C = grid[0].size();
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                prod[i][j] = grid[i][j];
                seen[i][j] = false;
            }
        }
        fill(grid, r0, c0, color);
        return grid;
    }

private:
    void fill(vector<vin>& grid, int r, int c, int p) {
        if (seen[r][c]) return;
        seen[r][c] = true;
        bool flag = false;
        for (int k = 0; k < 4; ++k) {
            int nc = c + moves[k][0];
            int nr = r + moves[k][1];
            if ((0 <= nc) && (nc < C) && (0 <= nr) &&
                (nr < R) && (prod[nr][nc] == prod[r][c])) {
                fill(grid, nr, nc, p);
            } else {
                flag = true;
            }
        }
        if (flag) {
            grid[r][c] = p;
        }
    }
};


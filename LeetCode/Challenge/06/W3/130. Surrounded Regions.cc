const int MAXK = 4;
const char WALL = 'X';
const int dir[MAXK][2] = {{-1,0}, {0,+1}, {+1,0}, {0,-1}};
vector<vector<char>> A;
vector<vector<bool>> seen;
int M, N;

struct Pair {
    int r, c;
};
vector<Pair> cur;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        A = move(board);
        N = A.size();
        M = A[0].size();
        seen.assign(N, vector<bool>(M, false));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (seen[i][j]) continue;
                cur.clear();
                if (dfs(i, j)) {
                    for (const auto& p: cur) {
                        A[p.r][p.c] = WALL;
                    }
                }
            }
        }
        board = move(A);
    }

private:
    bool dfs(int r, int c) {
        seen[r][c] = true;
        if (A[r][c] == WALL) {
            return true;
        }
        bool yes = true;
        for (int k = 0; k < MAXK; ++k) {
            int nr = r + dir[k][0];
            int nc = c + dir[k][1];
            if (!in_range(nr, nc)) {
                yes = false;
                continue;
            }
            if (seen[nr][nc]) {
                continue;
            }
            if (!dfs(nr, nc)) {
                yes = false;
            }
        }
        if (yes) {
            cur.push_back({r, c});
        }
        return yes;
    }

    bool in_range(int r, int c) {
        return (0 <= r) && (r < N) && (0 <= c) && (c < M);
    }
};

const int MAXK = 4;
const int dir[MAXK][2] = {{-1,0}, {0,+1}, {+1,0}, {0,-1}};

template <typename T>
using vec = vector<T>;

vec<vec<char>> A;
vec<vec<bool>> V;
string S;
int M, N;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        A = move(board);
        S = move(word);
        N = A.size();
        M = A[0].size();
        V.assign(N, vec<bool>(M, false));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (A[i][j] == S[0]) {
                    if (dfs(i, j, 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(int r, int c, unsigned p) {
        if (p == S.size()) {
            return true;
        }
        V[r][c] = true;
        unsigned np = p+1;
        for (int k = 0; k < MAXK; ++k) {
            int nr = r + dir[k][0];
            int nc = c + dir[k][1];
            if (!in_range(nr, nc)) {
                continue;
            }
            if (V[nr][nc] || (A[nr][nc] != S[p])) {
                continue;
            }
            if (dfs(nr, nc, np)) {
                return true;
            }
        }
        V[r][c] = false;
        return false;
    }

    bool in_range(int r, int c) {
        return (0 <= r) && (r < N) && (0 <= c) && (c < M);
    }
};

const int MAXN = 105;
const int MOVES[8][2] = {
    {-1, -1}, { 0, -1}, {+1, -1},
    {-1,  0},           {+1,  0},
    {-1, +1}, { 0, +1}, {+1, +1}
};
int dist[MAXN][MAXN];
queue<int> Q;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dist[i][j] = -1;
            }
        }
        queue<int>().swap(Q);
        if (grid[0][0] == 0) {
            dist[0][0] = 1;
            Q.push(0);
        }
        while (!Q.empty()) {
            int cur = Q.front();
            int cx = cur % N;
            int cy = cur / N;
            Q.pop();
            for (int k = 0; k < 8; ++k) {
                int nx = cx + MOVES[k][0];
                int ny = cy + MOVES[k][1];
                if ((0 <= nx) && (nx < N) && (0 <= ny) && (ny < N) &&
                    (grid[ny][nx] == 0) && (dist[ny][nx] == -1)) {
                    dist[ny][nx] = dist[cy][cx] + 1;
                    Q.push(ny * N + nx);
                }
            }
        }
        return dist[N-1][N-1];
    }
};

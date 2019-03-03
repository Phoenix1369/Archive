enum { NONE, FRESH, ROTTEN };
const int moves[4][2] = {{0,-1}, {+1,0}, {0,+1}, {-1,0}};   // NESW

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist = grid;
        std::queue<int> q;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dist[i][j] = -1;
                if (grid[i][j] == ROTTEN) {
                    dist[i][j] = 0;
                    grid[i][j] = NONE;
                    q.push(i*m + j);
                } else if (grid[i][j] == FRESH) {
                    ++cnt;
                }
            }
        }
        if (!cnt) {
            return 0;   // No fresh
        } else if (q.empty()) {
            return -1;  // Cannot rot
        }
        int ret = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            int cx = cur % m;
            int cy = cur / m;
            ret = max(dist[cy][cx], ret);
            for (int k = 0; k < 4; ++k) {
                int nx = cx + moves[k][0];
                int ny = cy + moves[k][1];
                if ((nx < 0) || (nx >= m) || (ny < 0) || (ny >= n)) continue;
                if (grid[ny][nx] == FRESH) {
                    dist[ny][nx] = dist[cy][cx] + 1;
                    grid[ny][nx] = NONE;
                    q.push(ny*m + nx);
                    --cnt;
                }
            }
        }
        return (cnt == 0) ? ret : -1;
    }
};

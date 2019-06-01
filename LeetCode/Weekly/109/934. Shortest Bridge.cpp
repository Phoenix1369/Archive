typedef vector<int> vin;
const int INFT = 1e4+5;
const vector<vin> moves{{0,-1},{1,0},{0,1},{-1,0}}; // NESW

class Solution {
    vector<vin> arr, dist;
    int n;
    
    queue<vin> q;
    
public:
    int shortestBridge(vector<vector<int>>& A) {
        arr = A;
        n = (int)arr.size();
        for (int i = 0; i < n; ++i) {
            dist.push_back(vin(n, INFT));
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i][j]) {
                    dfs(i, j);
                    i = n;
                    break;
                }
            }
        }
        
        int ret = 0;
        while (!q.empty()) {
            vin cur = q.front();
            if (arr[cur[0]][cur[1]] == 1) {
                ret = dist[cur[0]][cur[1]] - 1;
                break;
            }
            q.pop();
            for (auto mv: moves) {
                vin nxt{cur[0] + mv[0], cur[1] + mv[1]};
                if ((nxt[0] < 0) || (nxt[1] < 0) || (nxt[0] >= n) || (nxt[1] >= n)) continue;
                if (dist[nxt[0]][nxt[1]] == INFT) {
                    dist[nxt[0]][nxt[1]] = dist[cur[0]][cur[1]] + 1;
                    q.push({nxt[0], nxt[1]});
                }
            }
        }
        return ret;
    }
    
    void dfs(int i, int j) {
        if ((i < 0) || (j < 0) || (i >= n) || (j >= n)) return;
        if (arr[i][j] != 1) return;
        arr[i][j] = 2;
        dist[i][j] = 0;
        q.push({i, j});
        
        for (auto mv: moves) {
            dfs(i + mv[0], j + mv[1]);
        }
    }
};

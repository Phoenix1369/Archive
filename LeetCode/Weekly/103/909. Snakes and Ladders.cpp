const int INFN = 1e9+7;
const int MAXN = 30;
int seen[MAXN][MAXN]{ };

struct Node {
    int x, y, z;
    
    bool operator < (const Node &r) const {
        return z < r.z;
    }
};
typedef std::priority_queue<Node, std::vector<Node>> pq;

class Solution {
    int n;
    int n2;

    void incr(Node &p) {
        int &r = p.x;
        int &c = p.y;
        if ((r & 1) == (n & 1)) {
            // Heading left
            if(!c) {
                --r;
            } else {
                --c;
            }
        } else {
            if (c+1 == n) {
                --r;
            } else {
                ++c;
            }
        }
    }
    
    void jump(Node &p, int k) {
        int m = 1; // Moves
        int d = 1; // Direction
        int y = 0;
        for(int i = n-1; i >= 0; --i) {
            for(int j = 1; j < n; ++j) {
                if (m == k) {
                    p = { i, y, p.z };
                    return;
                }
                y += d;
                ++m;
            }
            if (m == k) {
                p = { i, y, p.z };
                return;
            }
            d *= -1;
            ++m;
        }
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n = (int)board.size();
        n2 = n*n;
        for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            seen[i][j] = INFN;

        pq Q;
        seen[n-1][0] = 0;
        Q.push({ n-1, 0, seen[n-1][0] });
        while(!Q.empty()) {
            Node cur = Q.top();
            Q.pop();
            cur.z *= -1;
            if (cur.z > seen[cur.x][cur.y]) continue;
            Node nxt = cur;
            for(int k = 1; k <= 6; ++k) {
                incr(nxt);
                if (nxt.x < 0) {
                    break;
                }
                Node cpy = nxt;
                if (board[nxt.x][nxt.y] != -1) {
                    jump(nxt, board[nxt.x][nxt.y]);
                }
                if (seen[nxt.x][nxt.y] > cur.z + 1) {
                    seen[nxt.x][nxt.y] = cur.z + 1;
                    nxt.z = -seen[nxt.x][nxt.y];
                    Q.push(nxt);
                }
                nxt = cpy;
            }
        }
        int c = (n & 1) ? (n-1) : 0;
        if (seen[0][c] == INFN) {
            seen[0][c] = -1;
        }
        return seen[0][c];
    }
};

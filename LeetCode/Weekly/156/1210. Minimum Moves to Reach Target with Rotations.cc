const int INFN = 1e9+7;
const int MAXN = 105;
int A[MAXN][MAXN];
int D[MAXN][MAXN][2];
int N;

const int FREE = 0;
const int RIGHT = 0;

struct Tri {
    int x, y;   // Track the top-left corner of the snake.
    int z;      // Orientation [right|down]
    
    Tri CW() const { return {x, y, z^1}; }
    Tri CCW() const { return {x, y, z^1}; }
    Tri down() const { return {x+1, y, z}; }
    Tri right() const { return {x, y+1, z}; }
    
    bool canCW() const { return isright() && isrowfree(); }
    bool canCCW() const { return isdown() && iscolfree(); }
    
    bool candown() const {
        if (isdown()) {
            return (x < N-2) && (A[x+2][y] == FREE);
        } else {
            return isrowfree();
        }
    }
        
    bool canright() const {
        if (isright()) {
            return (y < N-2) && (A[x][y+2] == FREE);
        } else {
            return iscolfree();
        }
    }
    
    bool isgoal() const {
        return (x == N-1) && (y == N-2) && isright();
    }
    
    bool isdown() const { return !isright(); }
    bool isright() const { return (z == RIGHT); }

private:
    bool iscolfree() const {
        return (y < N-1) && (A[x][y+1] == FREE) && (A[x+1][y+1] == FREE);
    }
    
    bool isrowfree() const {
        return (x < N-1) && (A[x+1][y] == FREE) && (A[x+1][y+1] == FREE);
    }
};

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        N = grid.size();
        init(grid);
        return bfs();
    }

private:    
    int bfs() {
        queue<Tri> Q;
        Q.push(Tri{0, 0, RIGHT});
        D[0][0][RIGHT] = 0;
        
        while (!Q.empty()) {
            Tri cur = Q.front();
            Q.pop();
            
            if (cur.isgoal()) {
                return D[cur.x][cur.y][cur.z];
            }
            
            if (cur.canCW())    enqueue(Q, cur, cur.CW());
            if (cur.canCCW())   enqueue(Q, cur, cur.CCW());
            if (cur.candown())  enqueue(Q, cur, cur.down());
            if (cur.canright()) enqueue(Q, cur, cur.right());
        }
        return -1;
    }
    
    void enqueue(queue<Tri>& Q, Tri& cur, Tri nxt) {
        if (D[nxt.x][nxt.y][nxt.z] == INFN) {
            D[nxt.x][nxt.y][nxt.z] = D[cur.x][cur.y][cur.z] + 1;
            Q.push(nxt);
        }
    }
    
    void init(const vector<vector<int>>& grid) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i][j] = grid[i][j];
                for (int k = 0; k < 2; ++k) {
                    D[i][j][k] = INFN;
                }
            }
        }
    }
};

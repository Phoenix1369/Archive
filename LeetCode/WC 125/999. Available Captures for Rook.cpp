const int MAXB = 8;
const int moves[4][2] = {{0,-1},{+1,0},{0,+1},{-1,0}};

class Solution {
    int rx, ry;
public:
    int numRookCaptures(vector<vector<char>>& board) {
        rx = ry = -1;
        find_rook(board);
        int ret = 0;
        for (int k = 0; k < 4; ++k) {
            for (int i = 1; i < MAXB; ++i) {
                int nx = rx + moves[k][0] * i;
                int ny = ry + moves[k][1] * i;
                if ((nx < 0) || (nx >= MAXB) ||
                    (ny < 0) || (ny >= MAXB) ||
                    (board[ny][nx] == 'B')) {
                    break;
                }
                if (board[ny][nx] == 'p') {
                    ++ret;
                    break;
                }
            }
        }
        return ret;
    }

private:
    void find_rook(const vector<vector<char>>& board) {
        for (int i = 0; i < MAXB; ++i) {
            for (int j = 0; j < MAXB; ++j) {
                if (board[i][j] == 'R') {
                    this->rx = j;
                    this->ry = i;
                    return;
                }
            }
        }
    }
};

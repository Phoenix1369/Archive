const int MAXB = 3;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int col[MAXB][2]{ };
        int row[MAXB][2]{ };
        int ldg[2]{ };
        int rdg[2]{ };
        int cur = 0;
        for (auto& move: moves) {
            int y = move[0];
            int x = move[1];
            if ((++col[x][cur] == MAXB) ||
                (++row[y][cur] == MAXB) ||
                ((x == y) && (++ldg[cur] == MAXB)) ||
                ((x + y + 1 == MAXB) && (++rdg[cur] == MAXB))) {
                return (cur == 0) ? "A" : "B";
            }
            cur ^= 1;
        }
        return (moves.size() == 9u) ? "Draw" : "Pending";
    }
};

/*
[[0,0],[2,0],[1,1],[2,1],[2,2]]
[[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
[[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
[[0,0],[1,1]]
>> "A"
>> "B"
>> "Draw"
>> "Pending"
*/

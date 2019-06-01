const int moves[4][2] = {{0,-1},{+1,0},{0,+1},{-1,0}};

struct Position { int d, x, y; };

class Solution {
    int N;

public:
    bool isRobotBounded(string instructions) {
        N = instructions.size();
        Position src = {0,0,0};
        for (int i = 0; i < 4; ++i) {
            for (auto cmd: instructions) {
                advance(src, cmd);
            }
        }
        return !src.x && !src.y;
    }

private:
    void advance(Position& src, char cmd) {
        switch (cmd) {
            case 'G':
                src.x += moves[src.d][0];
                src.y += moves[src.d][1];
                break;
            case 'L':
                src.d = (src.d + 3) % 4;
                break;
            case 'R':
                src.d = (src.d + 1) % 4;
                break;
        }
    }
};


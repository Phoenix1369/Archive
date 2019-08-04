const int W = 5;

class Solution {
public:
    string alphabetBoardPath(string target) {
        string ret;
        int cur = 0;
        for (char c: target) {
            int nxt = c - 'a';
            int dx = (nxt % W) - (cur % W);
            int dy = (nxt / W) - (cur / W);

            // U before R
            if (dx < 0) ret += string(-dx, 'L');
            if (dy < 0) ret += string(-dy, 'U');
            if (dx > 0) ret += string(dx, 'R');
            if (dy > 0) ret += string(dy, 'D');
            ret.push_back('!');
            cur = nxt;
        }
        return ret;
    }
};

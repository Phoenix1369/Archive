/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */
const int MAXS = MAXS;
Sea S;

vector<int> X;
int ret;

class Solution {
public:
    int countShips(Sea sea, vector<int> tr, vector<int> bl) {
        S = move(sea);
        X.clear();
        dfsX(bl, tr);
        if (X.size() == MAXS) {
            return MAXS;
        }
        ret = 0;
        for (int x: X) {
            dfsY({x, bl[1]}, {x, tr[1]});
        }
        return ret;
    }
    
    void dfsX(const vector<int>& bl, const vector<int>& tr) {
        if (!S.hasShips(tr, bl)) return;
        if (bl[0] == tr[0]) {
            X.push_back(bl[0]);
            return;
        }
        int midX = (bl[0] + tr[0]) / 2;
        dfsX(bl, {midX, tr[1]});
        dfsX({midX + 1, bl[1]}, tr);
    }
    
    void dfsY(const vector<int>& bl, const vector<int>& tr) {
        if (!S.hasShips(tr, bl)) return;
        if (bl[1] == tr[1]) {
            ++ret;
            return;
        }
        int midY = (bl[1] + tr[1]) / 2;
        dfsY(bl, {tr[0], midY});
        dfsY({bl[0], midY + 1}, tr);
    }
};

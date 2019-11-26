template <typename T>
using vec = vector<T>;
const int MAXK = 8;
const int MAXN = 8;
const int moves[MAXK][2] = {
    {-1,-1}, {-1,0}, {-1,1},
    { 0,-1},         { 0,1},
    { 1,-1}, { 1,0}, { 1,1}
};
bool A[MAXN][MAXN]{ };

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        init(queens);
        vec<vec<int>> ret;
        for (int k = 0; k < MAXK; ++k) {
            vec<int> cur = king;
            while (in_range(cur)) {
                if (A[cur[0]][cur[1]]) {
                    ret.push_back(cur);
                    break;
                }
                cur[0] += moves[k][0];
                cur[1] += moves[k][1];
            }
        }
        return ret;
    }
    
private:
    bool in_range(int& p) {
        return (0 <= p) && (p < MAXN);
    }
    
    bool in_range(vec<int>& p) {
        return in_range(p[0]) && in_range(p[1]);
    }
    
    void init(vec<vec<int>>& Q) {
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                A[i][j] = false;
            }
        }
        for (auto& cell: Q) {
            A[cell[0]][cell[1]] = true;
        }
    }
};

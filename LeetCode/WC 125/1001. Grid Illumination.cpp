typedef long long lld;
const int MAXV = 9;
const int moves[MAXV][2] = {
    {-1,-1},{ 0,-1},{+1,-1},
    {-1, 0},{ 0, 0},{+1, 0},
    {-1,+1},{ 0,+1},{+1,+1}
};

class Solution {
    map<int,int> ax, ay, dl, dr;
    set<lld> lit;
    vector<int> ret;
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        // Coordinate compression
        reset();
        for (auto lamp: lamps) {
            int x = lamp[0];
            int y = lamp[1];
            ++ax[x];
            ++ay[y];
            ++dl[x-y];
            ++dr[x+y];
            lit.insert(1LL*x*N + y);
        }
        for (auto q: queries) {
            int x = q[0];
            int y = q[1];
            ret.push_back(ax[x] || ay[y] || dl[x-y] || dr[x+y]);
            for (int k = 0; k < MAXV; ++k) {
                int nx = x + moves[k][0];
                int ny = y + moves[k][1];
                lld nxt = 1LL*nx*N + ny;
                if (lit.count(nxt)) {
                    lit.erase(nxt);
                    if (!--ax[nx]) {
                        ax.erase(nx);
                    }
                    if (!--ay[ny]) {
                        ay.erase(ny);
                    }
                    if (!--dl[nx-ny]) {
                        dl.erase(nx-ny);
                    }
                    if (!--dr[nx+ny]) {
                        dr.erase(nx+ny);
                    }
                }
            }
        }
        return ret;
    }

private:
    void reset() {
        ax.clear();
        ay.clear();
        dl.clear();
        dr.clear();
        lit.clear();
        ret.clear();
    }
};

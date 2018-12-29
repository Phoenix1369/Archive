const double EPS = 1e-5;
const unsigned INF = 4e9;

class Solution {
    unsigned sqr(int n) { return 1U*n*n; }

public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        double ret = INF;
        
        map<int, map<int, map<unsigned, set<pair<int,int>>>>> diag;
        for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j) {
            int x = points[i][0] + points[j][0];
            int y = points[i][1] + points[j][1];
            unsigned z = sqr(points[i][0] - points[j][0]) + sqr(points[i][1] - points[j][1]);
            
            diag[x][y][z].emplace(i, j);
        }
        
        for (const auto& X: diag)
        for (const auto& Y: X.second)
        for (const auto& Z: Y.second) {
            auto& V = Z.second;
            for (auto itr = V.begin(); itr != V.end(); ++itr) {
                auto jtr = itr;
                while (++jtr != V.end()) {
                    double a = sqrt(
                        sqr(points[itr->first][0] - points[jtr->first][0]) +
                        sqr(points[itr->first][1] - points[jtr->first][1])
                    );
                    double b = sqrt(
                        sqr(points[itr->second][0] - points[jtr->first][0]) +
                        sqr(points[itr->second][1] - points[jtr->first][1])
                    );
                    double c = fabs(a * b);
                    if (c > EPS) {
                        ret = min(c, ret);
                    }
                }
            }
        }
        
        if (fabs(ret - INF) < EPS) {
            ret = 0.0;
        }
        return ret;
    }
};

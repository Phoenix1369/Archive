struct Point {
    double x, y;
    
    double dist(const Point& o) const {
        return hypot(x - o.x, y - o.y);
    }
};

vector<Point> C;
vector<Point> P;
double R;
int N;

class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {
        P.clear();
        for (auto& p: points) {
            P.push_back({1.0 * p[0], 1.0 * p[1]});
        }
        N = P.size();
        R = r;
        int ret = 1;
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                centres(P[i], P[j]);
                for (auto& c: C) {
                    int cnt = 0;
                    for (int k = 0; k < N; ++k) {
                        if (c.dist(P[k]) <= R) ++cnt;
                    }
                    ret = max(cnt, ret);
                }
            }
        }
        return ret;
    }

private:
    void centres(const Point& p1, const Point& p2) {
        C.clear();
        double h = p1.dist(p2);
        if (h > R * 2.0) return;
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        double a = sqrt(sqr(R) - sqr(h / 2.0));
        double mdx = a * (dy / h);  // d * sin(theta)
        double mdy = a * (dx / h);  // d * cos(theta)
        double mx = (p1.x + p2.x) / 2.0;
        double my = (p1.y + p2.y) / 2.0;
        
        C.push_back({mx - mdx, my + mdy});
        C.push_back({mx + mdx, my - mdy});
    }
    
    double sqr(double x) { return x * x; }
};

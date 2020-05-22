#define ALL(x) (x).begin(), (x).end()
const double EPS = 1e-9;

struct Angle {
    double ang;
    int lvl;
    
    bool operator < (const Angle& o) const {
        return (fabs(ang - o.ang) > EPS) ? (ang < o.ang) : (lvl > o.lvl);
    }
};

struct Point {
    double x, y;
    
    bool operator == (const Point& o) const {
        return (x == o.x) && (y == o.y);
    }
    
    double dist(const Point& o) const {
        return hypot(x - o.x, y - o.y);
    }
};

vector<Angle> A;
vector<Point> P;
double R, R2;
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
        R2 = R * 2.0;
        
        int ret = 1;
        for (auto& p0: P) {
            A.clear();
            int cnt = 0;
            for (auto& p: P) {
                if (p0 == p) {
                    ++cnt;
                    continue;
                }
                angles(p0, p);
            }
            ret = max(cnt, ret);
            sort(ALL(A));
            for (auto& a: A) {
                cnt += a.lvl;
                ret = max(cnt, ret);
            }
        }
        return ret;
    }

private:
    void angles(const Point& p0, const Point& p) {
        double h = p0.dist(p);
        if (h > R2) return;
        double dx = p.x - p0.x;
        double dy = p.y - p0.y;
        double theta = atan2(dy, dx);
        double delta = acos(h / R2);
        
        A.push_back({theta - delta, +1});   // enter
        A.push_back({theta + delta, -1});   // exit
    }
};

const double EPS = 1e-6;
const int MAXL = 70;

const double ALPHA  = 0.7;
const int    CIRCLE = 360;
const double SCALE  = acos(-1) / 180.0;
const double STEP   = 100;

struct Point {
    double x, y;

    double dist(const Point& o) const {
        return hypot(x - o.x, y - o.y);
    }
};
vector<Point> P;
Point centre;
int N;

class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        N = positions.size();
        init();
        for (auto& pos: positions) {
            Point p{1.0 * pos[0], 1.0 * pos[1]};
            centre.x += p.x;
            centre.y += p.y;
            P.push_back(move(p));
        }
        centre.x /= N;
        centre.y /= N;
        double step = STEP;
        for (int i = 0; i < MAXL; ++i) {
            double error = f(centre);
            for (int deg = 0; deg < CIRCLE; ++deg) {
                double rad = deg * SCALE;
                Point candidate = {
                    centre.x + step * cos(rad),
                    centre.y + step * sin(rad)
                };
                double error2 = f(candidate);
                if (error2 < error) {
                    centre = move(candidate);
                    error = error2;
                }
            }
            step *= ALPHA;
        }
        return f(centre);
    }

private:
    double f(const Point& p) {
        double sum = 0.0;
        for (auto& q: P) {
            sum += p.dist(q);
        }
        return sum;
    }

    void init() {
        P.clear();
        centre.x = 0;
        centre.y = 0;
    }
};

#define ALL(x) (x).begin(), (x).end()
typedef vector<int> vin;
const int INFT = 1e9+7;
const int MAXP = 4e4+5;
unordered_map<int,int> cache;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        sort(ALL(points), [](const vin& lhs, const vin& rhs) {
            return (lhs[0] != rhs[0]) ? (lhs[0] < rhs[0]) : (lhs[1] < rhs[1]);
        });
        int sum = INFT;
        int N = points.size();
        cache.clear();
        cache.reserve(N*N);
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; (j < N) && (points[i][0] == points[j][0]); ++j) {
                int key = points[i][1] * MAXP + points[j][1];
                if (cache.count(key)) {
                    int dx = (points[j][0] - cache.at(key));
                    int dy = (points[j][1] - points[i][1]);
                    sum = min(dx * dy, sum);
                }
                cache[key] = points[j][0];
            }
        }
        return (sum < INFT) ? sum : 0;
    }
};


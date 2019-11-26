class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int N = points.size();
        int ret = 0;
        for (int i = 1; i < N; ++i) {
            int dx = abs(points[i][0] - points[i-1][0]);
            int dy = abs(points[i][1] - points[i-1][1]);
            ret += max(dx, dy);
        }
        return ret;
    }
};

/*
[[1,1],[3,4],[-1,0]]
[[3,2],[-2,2]]
>> 7
>> 5
*/

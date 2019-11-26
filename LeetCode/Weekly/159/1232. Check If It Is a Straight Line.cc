vector<vector<int>> C;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        C = move(coordinates);
        int N = C.size();
        for (int i = 2; i < N; ++i) {
            if (!monotonic(i)) {
                return false;
            }
        }
        return true;
    }

private:
    bool monotonic(int i) {
        return
            ((C[i][0] - C[i-2][0]) * (C[i-1][1] - C[i][1])) ==
            ((C[i][1] - C[i-2][1]) * (C[i-1][0] - C[i][0]));
    }
};

/*
[[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
[[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
>> true
>> false
*/

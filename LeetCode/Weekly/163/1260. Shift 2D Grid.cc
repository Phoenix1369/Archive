template <typename T>
using vec = vector<T>;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int K) {
        int N = grid.size();
        int M = grid[0].size();
        int H = M * N;
        K %= H;
        K = (H - K) % H;
        
        vec<vec<int>> ret;
        for (int i = 0; i < N; ++i) {
            ret.emplace_back();
            for (int j = 0; j < M; ++j) {
                int cur = i * M + j;
                int old = (cur + K) % H;
                int x = old % M;
                int y = old / M;
                ret.back().push_back(grid[y][x]);
            }
        }
        return ret;
    }
};

/*
[[1,2,3],[4,5,6],[7,8,9]]
1
[[1,2,3],[4,5,6],[7,8,9]]
2
[[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]
4
[[1,2,3],[4,5,6],[7,8,9]]
9
>> [[9,1,2],[3,4,5],[6,7,8]]
>> [[8,9,1],[2,3,4],[5,6,7]]
>> [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
>> [[1,2,3],[4,5,6],[7,8,9]]
*/

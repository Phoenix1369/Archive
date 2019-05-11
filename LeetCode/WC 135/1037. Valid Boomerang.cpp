class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int M[2][2] = {
            {points[0][0] - points[1][0], points[1][0] - points[2][0]},
            {points[0][1] - points[1][1], points[1][1] - points[2][1]}
        };
        // Boomerang <=> Triangle with positive arena.
        return M[0][0] * M[1][1] != M[1][0] * M[0][1];
    }
};

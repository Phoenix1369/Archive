/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */
typedef vector<int> vin;
const int MAXN = 1001;

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vin> res;
        for (int i = 1; i < MAXN; ++i) {
            for (int j = 1; j < MAXN; ++j) {
                if (customfunction.f(i, j) == z) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};

/*
1
5
2
5
>> [[1,4],[2,3],[3,2],[4,1]]
>> [[1,5],[5,1]]
*/

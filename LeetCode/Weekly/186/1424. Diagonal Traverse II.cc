const int MAXC = 2e5+5;
vector<int> D[MAXC];
int K, M, N;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        N = nums.size();
        M = 0;
        for (const auto& row: nums) {
            M = max((int)row.size(), M);
        }
        K = N + M;
        init();
        for (int i = 0; i < N; ++i) {
            for (unsigned j = 0; j < nums[i].size(); ++j) {
                D[i + j].push_back(nums[i][j]);
            }
        }
        vector<int> ret;
        ret.reserve(N + M);
        for (int i = 0; i < K; ++i) {
            for (int j = D[i].size(); j > 0; --j) {
                ret.push_back(D[i][j-1]);
            }
        }
        return ret;
    }

private:
    void init() {
        for (int i = 0; i < K; ++i) {
            D[i].clear();
        }
    }
};

#define ALL(x) (x).begin(), (x).end()

template <typename T>
using vec = vector<T>;

unordered_map<int,int> C;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int N = nums.size();
        C.clear();
        C.reserve(N);
        vec<vec<int>> ret;
        for (int i = 0; i < N; ++i) {
            ++C[nums[i]];
        }
        for (auto& itr: C) {
            for (auto& jtr: C) {
                int i = itr.first;
                int j = jtr.first;
                if (i > j) {
                    continue;
                }
                if ((i == j) && (itr.second < 2)) {
                    continue;
                }
                --itr.second;
                --jtr.second;
                int k = -(i + j);
                if ((j <= k) && C.count(k) && C.at(k)) {
                    ret.push_back({i, j, k});
                }
                ++jtr.second;
                ++itr.second;
            }
        }
        return ret;
    }
};

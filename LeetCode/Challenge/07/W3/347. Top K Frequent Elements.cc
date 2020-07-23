template <typename T>
using vec = vector<T>;

unordered_map<int,int> cnt;
vec<vec<int>> dnt;
int N;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        N = nums.size();
        init();
        for (int x: nums) {
            ++cnt[x];
        }
        for (auto itr: cnt) {
            dnt[itr.second].push_back(itr.first);
        }
        vector<int> ret;
        for (int i = N; (i >= 1) && (k > 0); --i) {
            for (int j: dnt[i]) {
                ret.push_back(j);
                --k;
            }
        }
        return ret;
    }

private:
    void init() {
        cnt.clear();
        cnt.reserve(N);
        dnt.assign(N+1, vec<int>());
    }
};

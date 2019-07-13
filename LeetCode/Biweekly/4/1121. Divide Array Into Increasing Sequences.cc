const int MAXN = 1e5+5;
vector<int> pos[MAXN];
int idx[MAXN];

map<int,vector<int>> seq;

class Solution {
    // We may only start sequences with the H = N / K smallest values.
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        seq.clear();
        int N = nums.size();
        int H = N / K;

        nums.insert(nums.begin(), 0);
        for (int i = 0; i < MAXN; ++i) {
            pos[i].clear();
            idx[i] = 0;
        }
        for (int i = 1; i <= N; ++i) {
            pos[nums[i]].push_back(i);
        }
        for (int h=0, i=0; (h < H) && (i < MAXN); ++i) {
            for (auto jtr: pos[i]) {
                ++idx[jtr];
                if (++h >= H) break;
            }
        }
        for (int i = 1; i <= N; ++i) {
            idx[i] += idx[i-1];
        }

        for (int i = 1; i <= N; ++i) {
            if (idx[i] > idx[i-1]) {
                seq[nums[i]].push_back(1);
                continue;
            }

            // Augment
            auto ptr = seq.lower_bound(nums[i]);
            if (ptr == seq.begin()) {
                return false;
            }
            --ptr;
            int val = ptr->first;
            auto ps = ptr->second;
            auto last = ps.back();
            seq[nums[i]].push_back(last + 1);
            seq[val].pop_back();
            if (seq[val].empty()) {
                seq.erase(val);
            }
        }
        return true;
    }
};

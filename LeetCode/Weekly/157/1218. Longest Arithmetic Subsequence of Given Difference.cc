unordered_map<int,int> seen;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int N = arr.size();
        seen.clear();
        seen.reserve(N);
        for (auto num: arr) {
            int prev = num - difference;
            int chain = (seen.count(prev) ? seen.at(prev) : 0);
            seen[num] = chain + 1;
        }
        int ret = 0;
        for (auto itr: seen) {
            ret = max(itr.second, ret);
        }
        return ret;
    }
};

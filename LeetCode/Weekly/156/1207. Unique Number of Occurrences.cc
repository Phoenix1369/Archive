unordered_map<int,int> cnt;
unordered_set<int> dnt;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        cnt.clear();
        dnt.clear();
        
        cnt.reserve(arr.size());
        for (int num: arr) {
            ++cnt[num];
        }
        
        dnt.reserve(cnt.size());
        for (auto itr: cnt) {
            if (dnt.count(itr.second)) {
                return false;
            }
            dnt.insert(itr.second);
        }
        return true;
    }
};

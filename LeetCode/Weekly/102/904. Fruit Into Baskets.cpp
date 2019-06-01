class Solution {
public:
    int totalFruit(vector<int>& tree) {
        std::map<int,int> last;
        std::set<int> f;
        int n = (int)tree.size();

        int cur=0, ret=0;
        for(int i = 0; i < n; ++i) {
            last[tree[i]] = i;
            f.insert(tree[i]);
            if(f.size() > 2U) {
                int old = tree[i];
                for(int j: f) {
                    if(last.at(j) < last.at(old)) {
                        old = j;
                    }
                }
                f.erase(old);
                ret = std::max(cur, ret);
                cur = i-last.at(old);
            } else {
                ++cur;
            }
        }
        return ret = std::max(cur, ret);
    }
};

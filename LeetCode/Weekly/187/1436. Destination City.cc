class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int M = paths.size();
        unordered_map<string,int> deg;
        deg.reserve(M+1);
        for (auto& edge: paths) {
            --deg[edge[0]];
            ++deg[edge[1]];
        }
        for (const auto& itr: deg) {
            if (itr.second == 1) {
                return itr.first;
            }
        }
        return "";
    }
};

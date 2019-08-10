const int MAXN = 55;
map<vector<string>, set<string>> cnt;
int I[MAXN];

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int N = username.size();
        cnt.clear();
        iota(I, I+N, 0);
        sort(I, I+N, [&](int lhs, int rhs) {
            return timestamp[lhs] < timestamp[rhs];
        });

        int ret = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                if (username[I[i]] != username[I[j]]) continue;
                for (int k = j+1; k < N; ++k) {
                    if (username[I[i]] != username[I[k]]) continue;

                    auto key = {website[I[i]], website[I[j]], website[I[k]]};
                    cnt[key].insert(username[I[i]]);
                    
                    int sz = cnt[key].size();
                    ret = max(sz, ret);
                }
            }
        }

        for (auto itr: cnt) {
            if (itr.second.size() == ret) {
                return itr.first;
            }
        }
        return {};
    }
};

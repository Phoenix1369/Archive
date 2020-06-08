#define ALL(x) (x).begin(), (x).end()
template <typename T>
using vec = vector<T>;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(ALL(people), [](const vec<int>& lhs, const vec<int>& rhs) {
            return (lhs[1] != rhs[1])
                ?  (lhs[1] <  rhs[1])
                :  (lhs[0] <  rhs[0]);
        });
        vec<vec<int>> ret;
        for (const auto& p: people) {
            int cnt = 0;
            auto itr = ret.begin();
            while (itr != ret.end()) {
                if ((*itr)[0] >= p[0]) {
                    if (++cnt >  p[1]) break;
                }
                ++itr;
            }
            ret.insert(itr, p);
        }
        return ret;
    }
};

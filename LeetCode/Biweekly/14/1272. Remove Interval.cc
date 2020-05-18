template <typename T>
using vec = vector<T>;

class Solution {
public:
    vec<vec<int>> removeInterval(vec<vec<int>> I, vec<int> R) {
        vec<vec<int>> ret;
        for (auto itr: I) {
            int head = itr[0];
            int tail = itr[1];
            if (head < R[0]) {
                ret.push_back({head, min(tail, R[0])});
            }
            if (tail > R[1]) {
                ret.push_back({max(head, R[1]), tail});
            }
        }
        return ret;
    }
};

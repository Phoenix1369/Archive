#define ALL(x) (x).begin(), (x).end()
typedef std::vector<int> vin;

class Solution {
    int cur, nxt, ret;
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(ALL(clips), [&](const vin& lhs, const vin& rhs) {
            if (lhs[0] != rhs[0]) {
                return lhs[0] < rhs[0];
            }
            return lhs[1] > rhs[1];
        });
        bool first = true;
        cur = nxt = ret = 0;
        for (auto clip: clips) {
            if (cur >= T) {
                break;
            }
            if (clip[0] > nxt) {
                return -1;
            }
            if (first) {
                first = false;
                cur = nxt = clip[1];
                ++ret;
                continue;
            }
            if (clip[0] <= cur) {
                nxt = max(clip[1], nxt);
            } else {
                cur = nxt;
                ++ret;
            }
        }
        if (cur < T) {
            if (nxt >= T) {
                cur = nxt;
                ++ret;
            } else {
                return -1;
            }
        }
        return ret;
    }
};

#define CLR(x) memset((x), 0, sizeof(x))
const int MAXK = 1e5+5;
int cnt[MAXK];

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        CLR(cnt);
        for (int x: arr) {
            x %= k;
            if (x < 0) x += k;
            ++cnt[x];
        }
        for (int i = 0; i < k; ++i) {
            int j = (k - i) % k;
            if (j == i) {
                if (cnt[i] & 1) {
                    return false;
                }
            } else {
                if (cnt[i] != cnt[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

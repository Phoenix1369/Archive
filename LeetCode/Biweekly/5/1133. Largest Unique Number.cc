const int MAXA = 1005;
int cnt[MAXA];

class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        for (int i = 0; i < MAXA; ++i) {
            cnt[i] = 0;
        }
        for (int a: A) {
            ++cnt[a];
        }
        for (int i = MAXA-1; i >= 0; --i) {
            if (cnt[i] == 1) {
                return i;
            }
        }
        return -1;
    }
};

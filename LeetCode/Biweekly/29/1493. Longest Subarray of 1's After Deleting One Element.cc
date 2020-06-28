vector<int> C;
int cnt;
int ret;
int y;
bool z;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        C.clear();
        cnt = 0;
        ret = 0;
        y = 1;
        z = false;
        for (int x: nums) {
            if (x != y) {
                flush();
            }
            ++cnt;
        }
        flush();
        if (!z) {
            if (ret) --ret;
            return ret;
        }
        return merge();
    }

private:
    int merge() {
        int K = C.size();
        for (int i = 1; i+1 < K; i += 2) {
            if (C[i] == 1) {
                ret = max(C[i-1] + C[i+1], ret);
            }
        }
        return ret;
    }

    void flush() {
        C.push_back(cnt);
        if (y == 1) {
            ret = max(cnt, ret);
        } else {
            z |= (cnt != 0);
        }
        y ^= 1;
        cnt = 0;
    }
};

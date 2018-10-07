const int MAXA = 128;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int dict[MAXA]{ };
        int n = (int)s.size();
        int head=0, tail=0;
        bool dup = false;
        int ret=0;
        while (tail < n) {
            ++dict[s[tail]];
            if (dict[s[tail]] > 1) {
                dup = true;
            }
            while (dup) {
                --dict[s[head]];
                if (dict[s[head]] == 1) {
                    dup = false;
                }
                ++head;
            }
            ret = max(tail-head+1, ret);
            ++tail;
        }
        return ret;
    }
};

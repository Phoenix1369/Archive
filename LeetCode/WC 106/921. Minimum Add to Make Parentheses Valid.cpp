class Solution {
public:
    int minAddToMakeValid(string S) {
        int ret = 0;
        int left = 0;
        for (const char& c: S) {
            if (c == '(') {
                ++left;
            } else if (!left) {
                ++ret;
            } else {
                --left;
            }
        }
        ret += left;
        return ret;
    }
};

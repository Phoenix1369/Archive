class Solution {
public:
    string generateTheString(int n) {
        string ret(n, 'a');
        if ((n & 1) == 0) ret.back() = 'b';
        return ret;
    }
};

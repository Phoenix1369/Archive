class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ret;
        int bra = 0;
        int lvl = 0;
        // Greedily take '('
        for (char c: s) {
            if (c == '(') {
                ret.push_back(c);
                ++lvl;
                ++bra;
            } else if (c == ')') {
                if (lvl) {
                    ret.push_back(c);
                    --lvl;
                }
            } else {
                ret.push_back(c);
            }
        }

        string res;
        bra -= lvl;
        // Greedily omit '('
        for (char c: ret) {
            if (c == '(') {
                if (bra) {
                    res.push_back(c);
                    --bra;
                }
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};

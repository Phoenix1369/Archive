class Solution {
public:
    string removeOuterParentheses(string S) {
        string ret;
        int lvl = 0;
        int back = 0;
        for (char c: S) {
            if (c == '(') {
                ret.append(1, c);
                ++lvl;
            } else {
                // (c == ')')
                if (!--lvl) {
                    ret.erase(back, 1);
                    back = ret.size();
                } else {
                    ret.append(1, c);
                }
            }
        }
        return ret;
    }
};

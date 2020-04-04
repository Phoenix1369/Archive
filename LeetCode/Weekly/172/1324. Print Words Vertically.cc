class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ret;
        int row = 0;
        int col = 0;
        for (char c: s) {
            if (c == ' ') {
                row = 0;
                ++col;
                continue;
            }
            if (row == (int)ret.size()) {
                ret.push_back("");
            }
            while (ret[row].size() < col) {
                ret[row].push_back(' ');
            }
            ret[row].push_back(c);
            ++row;
        }
        return ret;
    }
};

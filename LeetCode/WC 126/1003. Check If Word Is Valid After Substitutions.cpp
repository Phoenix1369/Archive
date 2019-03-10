const string V = "abc";
vector<char> stk;

class Solution {
public:
    bool isValid(string S) {
        stk.clear();
        for (auto& c: S) {
            if (c == 'a') {
                stk.push_back(c);
            } else if (c == 'b') {
                if (stk.empty() || (stk.back() == 'b')) {
                    return false;
                }
                if (stk.back() == 'a') {
                    stk.back() = 'b';
                }
            } else if (c == 'c') {
                if (stk.empty() || (stk.back() == 'a')) {
                    return false;
                }
                if (stk.back() == 'b') {
                    stk.pop_back();
                }
            }
        }
        return stk.empty();
    }
};
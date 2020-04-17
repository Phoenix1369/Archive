#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    bool checkValidString(string s) {
        return check(s) && check(invert(s));
    }

private:
    bool check(const string& s) {
        int lvl = 0;
        int wild = 0;
        for (const char& c: s) {
            if (c == '(') {
                ++lvl;
            } else if (c == ')') {
                if (lvl <= 0) {
                    // Freely convert wildcards to '('
                    if (wild) {
                        --wild;
                    } else {
                        return false;
                    }
                } else {
                    --lvl;
                }
            } else {
                // (c == '*')
                ++wild;
            }
        }
        // Generously close off remaining '('
        return (lvl <= wild);
    }
    
    string& invert(string& s) {
        reverse(ALL(s));
        for (char& c: s) {
            if (c == '(') {
                c = ')';
            } else if (c == ')') {
                c = '(';
            }
        }
        return s;
    }
};

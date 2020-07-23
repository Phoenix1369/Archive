#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    string reverseWords(string s) {
        reverse(ALL(s));
        istringstream iss{s};
        ostringstream oss;
        while (iss >> s) {
            if (oss.tellp()) {
                oss << ' ';
            }
            reverse(ALL(s));
            oss << s;
        }
        return oss.str();
    }
};

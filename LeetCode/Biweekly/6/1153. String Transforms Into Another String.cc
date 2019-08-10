const int MAXA = 26;
map<char,char> to;
set<char> dest;

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1.compare(str2) == 0) {
            return true;
        }

        int N = str1.size();
        to.clear();
        dest.clear();
        for (int i = 0; i < N; ++i) {
            if (!to.count(str1[i])) {
                to[str1[i]] = str2[i];
            } else if (to[str1[i]] != str2[i]) {
                return false;
            }
            dest.insert(str2[i]);
        }
        if ((to.size() == MAXA) && (dest.size() == MAXA)) {
            return false;
        }
        return true;
    }
};

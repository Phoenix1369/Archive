class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ret = 0;
        for (char c: S) {
            if (J.find(c) != string::npos) ++ret;
        }
        return ret;
    }
};

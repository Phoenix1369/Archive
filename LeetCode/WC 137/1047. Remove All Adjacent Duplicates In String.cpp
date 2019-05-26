class Solution {
    string res;

public:
    string removeDuplicates(string S) {
        res.clear();
        for (char c: S) {
            if (res.empty() || res.back() != c) {
                res.push_back(c);
            } else {
                res.pop_back();
            }
        }
        return res;
    }
};


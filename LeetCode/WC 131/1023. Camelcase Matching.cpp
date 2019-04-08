class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (auto query: queries) {
            res.push_back(solve(query, pattern));
        }
        return res;
    }

private:
    bool solve(const string& query, const string& pattern) {
        int pos = 0;
        for (char q: query) {
            if ((pos >= pattern.size()) || (q != pattern[pos])) {
                if (isupper(q)) {
                    return false;
                }
            } else {
                ++pos;
            }
        }
        return (pos >= pattern.size());
    }
};

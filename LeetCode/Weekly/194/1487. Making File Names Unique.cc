unordered_map<string, int> seen;
int N;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        N = names.size();
        init();
        vector<string> ret;
        for (string& s: names) {
            string t = s;
            if (seen.count(s)) {
                int pos = seen.at(s);
                do {
                    t = s + "(" + to_string(pos) + ")";
                    ++pos;
                } while (seen.count(t));
                seen[s] = pos;
            }
            seen[t] = 1;
            ret.push_back(t);
        }
        return ret;
    }

private:
    void init() {
        seen.clear();
        seen.reserve(N);
    }
};

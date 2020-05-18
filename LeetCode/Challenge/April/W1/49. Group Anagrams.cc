#define ALL(x) (x).begin(), (x).end()

typedef string str;

template <typename T>
using vec = vector<T>;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<str, vec<str>> data;
        data.reserve(strs.size());
        for (str& s: strs) {
            str t = s;
            sort(ALL(t));
            data[t].push_back(s);
        }
        vec<vec<str>> ret;
        for (auto& itr: data) {
            ret.push_back(itr.second);
        }
        return ret;
    }
};

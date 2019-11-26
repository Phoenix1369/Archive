#define ALL(x) (x).begin(), (x).end()
typedef string str;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(ALL(folder));
        vector<str> ret;
        for (str& f: folder) {
            if (ret.empty()) {
                ret.push_back(f);
                continue;
            }
            str& s = ret.back();
            if ((f.compare(0, s.size(), s) != 0) ||
                (f[s.size()] != '/')) {
                ret.push_back(f);
            }
        }
        return ret;
    }
};

/*
["/a","/a/b","/c/d","/c/d/e","/c/f"]
["/a","/a/b/c","/a/b/d"]
["/a/b/c","/a/b/ca","/a/b/d"]
>> ["/a","/c/d","/c/f"]
>> ["/a"]
>> ["/a/b/c","/a/b/ca","/a/b/d"]
*/

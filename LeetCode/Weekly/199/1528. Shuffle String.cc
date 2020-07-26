class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int N = s.size();
        string t = s;
        for (int i = 0; i < N; ++i) {
            t[indices[i]] = s[i];
        }
        return t;
    }
};

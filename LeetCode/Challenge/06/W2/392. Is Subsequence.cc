class Solution {
public:
    bool isSubsequence(string s, string t) {
        int N = s.size();
        int M = t.size();
        int j = 0;
        for (int i = 0; (i < M) && (j < N); ++i) {
            if (s[j] == t[i]) ++j;
        }
        return (j == N);
    }
};

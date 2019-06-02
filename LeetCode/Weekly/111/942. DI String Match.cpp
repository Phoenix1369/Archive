vector<int> res;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int N = S.size();
        res.clear();
        res.reserve(N + 1);
        res.push_back(0);
        int mn = 0;
        int mx = 0;
        for (int i = 0; i < N; ++i) {
            if (S[i] == 'D') {
                res.push_back(--mn);
            } else {
                res.push_back(++mx);
            }
        }
        for (int i = 0; i <= N; ++i) {
            res[i] -= mn;
        }
        return res;
    }
};

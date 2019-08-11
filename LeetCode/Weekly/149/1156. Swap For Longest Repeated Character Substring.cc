class Solution {
    vector<int> seg;
    int N;

public:
    int maxRepOpt1(string text) {
        N = text.size();
        int ret = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            ret = max(solve(text, c), ret);
        }
        return ret;
    }

private:
    int solve(const string& S, char c) {
        seg.clear();
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            if (S[i] == c) ++cnt;
        }

        // Alternating Segments
        for (int i = 0; i < N;) {
            int j = i;
            while ((i < N) && (S[i] != c)) ++i;
            seg.push_back(i - j);
            j = i;
            while ((i < N) && (S[i] == c)) ++i;
            seg.push_back(i - j);
        }
        if (!seg.empty() && !seg.back()) {
            seg.pop_back();
            seg.pop_back();
        }
        int M = seg.size();

        // 1. Merge Adjacent
        // 2. Augment Single
        int res = 0;
        int solo = (M >= 4) ? 1 : 0;
        int mult = (M >= 6) ? 1 : 0;
        for (int i = 1; i < M; i += 2) {
            if ((i+2 < M) && (seg[i+1] <= 1)) {
                res = max(seg[i] + seg[i+2] + mult, res);
            }
            res = max(seg[i] + solo, res);
        }
        return res;
    }
};

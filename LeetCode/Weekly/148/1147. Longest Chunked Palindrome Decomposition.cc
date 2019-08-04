class Solution {
    string S;
    int N;

public:
    int longestDecomposition(string text) {
        S = move(text);
        N = S.size();
        return solve(0, N-1);
    }

private:
    int solve(int l, int r) {
        if (l - 1 == r) {
            return 0;
        }
        for (int k = 0; l+k < r-k; ++k) {
            bool yes = true;
            for (int i = 0; i <= k; ++i) {
                if (S[l+i] != S[r-(k-i)]) {
                    yes = false;
                    break;
                }
            }
            if (yes) {
                return 2 + solve(l+k+1, r-k-1);
            }
        }
        return 1;
    }
};

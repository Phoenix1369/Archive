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
            if (S.compare(l, k+1, S, r-k, k+1) == 0) {
                return 2 + solve(l+k+1, r-k-1);
            }
        }
        return 1;
    }
};

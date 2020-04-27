class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) {
            return 0;
        }
        if (palindrome(s)) {
            return 1;
        }
        return 2;
    }

private:
    bool palindrome(const string& S) {
        int N = S.size();
        int lo = 0;
        int hi = N-1;
        while (lo < hi) {
            if (S[lo] != S[hi]) {
                return false;
            }
            ++lo;
            --hi;
        }
        return true;
    }
};

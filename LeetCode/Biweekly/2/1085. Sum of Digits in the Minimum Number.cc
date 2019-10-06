#define ALL(x) (x).begin(), (x).end()
const int BASE = 10;

class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int M = *min_element(ALL(A));
        int S = digitsum(M) & 1;
        return (S ^ 1);
    }

private:
    int digitsum(int n) {
        int ans = 0;
        while (n) {
            ans += n % BASE;
            n /= BASE;
        }
        return ans;
    }
};

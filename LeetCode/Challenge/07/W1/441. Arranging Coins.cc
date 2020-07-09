typedef long long lld;

class Solution {
public:
    int arrangeCoins(int n) {
        int k = sqrt(2u * n);
        return (n >= sum(k)) ? k : (k-1);
    }

private:
    lld sum(int x) {
        return 1LL * x * (x+1) / 2;
    }
};

const int BASE = 10;
const int MAXN = 105;
unordered_set<int> seen;

class Solution {
public:
    bool isHappy(int n) {
        seen.clear();
        seen.reserve(MAXN);
        return dfs(n);
    }

private:
    bool dfs(int n) {
        if (n == 1) {
            return true;
        }
        if (seen.count(n)) {
            return false;
        }
        seen.insert(n);
        return dfs(squared_digit_sum(n));
    }
    
    int sqr(int n) {
        return 1LL * n * n;
    }
    
    int squared_digit_sum(int n) {
        int sum = 0;
        while (n) {
            sum += sqr(n % BASE);
            n /= BASE;
        }
        return sum;
    }
};

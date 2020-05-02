const int MAXN = 1e4+5;
const int K = 4;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ret = 0;
        for (int x: nums) {
            ret += divisors(x);
        }
        return ret;
    }

private:
    int divisors(int x) {
        int s = sqrt(x);
        int cnt = 0;
        int sum = 0;
        for (int i = 1; i <= s; ++i) {
            if ((x % i) != 0) continue;
            sum += i;
            ++cnt;
            int j = x / i;
            if (i != j) {
                sum += j;
                ++cnt;
            }
            if (cnt > K) break;
        }
        return (cnt == K) ? sum : 0;
    }
};

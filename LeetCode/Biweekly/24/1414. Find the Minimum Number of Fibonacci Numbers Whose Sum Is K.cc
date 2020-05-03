const int MAXF = 45;
int F[MAXF];

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        init();
        int cnt = 0;
        for (int i = MAXF-1; k && (i >= 0); --i) {
            while (k >= F[i]) {
                k -= F[i];
                ++cnt;
            }
        }
        return cnt;
    }

private:
    void init() {
        F[0] = 0;
        F[1] = 1;
        for (int i = 2; i < MAXF; ++i) {
            F[i] = F[i-1] + F[i-2];
        }
    }
};

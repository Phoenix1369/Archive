#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int effect = 0;
        for (int i = 0; i < X; ++i) {
            if (grumpy[i]) {
                effect += customers[i];
            }
        }
        int N = customers.size();
        int best = effect;
        for (int i = X; i < N; ++i) {
            if (grumpy[i]) effect += customers[i];
            if (grumpy[i-X]) effect -= customers[i-X];
            best = max(effect, best);
        }
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            if (!grumpy[i]) {
                sum += customers[i];
            }
        }
        return (sum + best);
    }
};

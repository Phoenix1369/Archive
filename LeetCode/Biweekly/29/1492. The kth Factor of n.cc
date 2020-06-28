#define ALL(x) (x).begin(), (x).end()
vector<int> F;

class Solution {
public:
    int kthFactor(int n, int k) {
        F.clear();
        int s = sqrt(n);
        for (int i = 1; i <= s; ++i) {
            if (n % i) continue;
            int j = n / i;
            F.push_back(i);
            if (j != i) {
                F.push_back(j);
            }
        }
        sort(ALL(F));
        --k;
        return (k < F.size()) ? F[k] : -1;
    }
};

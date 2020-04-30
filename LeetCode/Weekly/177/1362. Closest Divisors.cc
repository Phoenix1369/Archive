vector<int> ret[2];
int K;

class Solution {
public:
    vector<int> closestDivisors(int num) {
        K = ++num;
        int pos = (find(0) < find(1)) ? 0 : 1;
        return ret[pos];
    }

private:
    int find(int x) {
        int N = K + x;
        int S = sqrt(N);
        for (int i = S; i >= 1; --i) {
            if ((N % i) == 0) {
                int j = N / i;
                ret[x].assign({i, j});
                return (j - i);
            }
        }
        return 0;
    }
};

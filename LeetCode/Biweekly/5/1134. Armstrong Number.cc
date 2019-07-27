const int BASE = 10;
vector<int> D;

class Solution {
public:
    bool isArmstrong(int N) {
        D.clear();
        for (int n = N; n; n /= BASE) {
            D.push_back(n % BASE);
        }
        int M = D.size();
        int ret = 0;
        for (auto d: D) {
            int v = 1;
            for (int i = 0; i < M; ++i) {
                v *= d;
            }
            ret += v;
        }
        return (ret == N);
    }
};

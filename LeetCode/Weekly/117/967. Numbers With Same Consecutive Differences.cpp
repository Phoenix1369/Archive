class Solution {
    const int MAXB = 10;
    const vector<int> single = {1,2,3,4,5,6,7,8,9,0};
    vector<int> res;

public:
    vector<int> numsSameConsecDiff(int N, int K) {
        res = single;
        if (N > 1) res.pop_back();
        for (int i = 1; i < N; ++i) {
            vector<int> cpy = move(res);
            for (auto& num: cpy) {
                int rem = num % MAXB;
                if (rem + K < MAXB) {
                    res.push_back(num * 10 + rem + K);
                }
                if (K && (rem >= K)) {
                    res.push_back(num * 10 + rem - K);
                }
            }
        }
        return res;
    }
};

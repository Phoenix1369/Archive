const int MOD = 5;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int sum = 0;
        for (auto a: A) {
            sum = (2LL*sum + a) % MOD;
            res.push_back(!(sum % 5));
        }
        return res;
    }
};

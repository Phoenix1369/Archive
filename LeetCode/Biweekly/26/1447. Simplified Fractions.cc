class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ret;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                int k = gcd(i, j);
                if (k != 1) continue;
                ret.push_back(to_string(j) + "/" + to_string(i));
            }
        }
        return ret;
    }
};

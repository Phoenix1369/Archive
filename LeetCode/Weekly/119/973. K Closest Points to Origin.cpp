typedef vector<int> vin;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& P, int K) {
        auto pred = [&](const vin& lhs, const vin& rhs) {
            return sqr(lhs[0]) + sqr(lhs[1]) < sqr(rhs[0]) + sqr(rhs[1]);
        };
        nth_element(P.begin(), P.begin() + K, P.end(), pred);
        P.erase(P.begin() + K, P.end());
        return P;
    }

private:
    int sqr(int x) { return x * x; }
};

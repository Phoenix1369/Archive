#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int N = candies.size();
        int best = *max_element(ALL(candies));
        vector<bool> ret(N, false);
        for (int i = 0; i < N; ++i) {
            ret[i] = (candies[i] + extraCandies >= best);
        }
        return ret;
    }
};

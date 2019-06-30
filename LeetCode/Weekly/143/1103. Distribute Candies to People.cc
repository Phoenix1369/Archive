class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int N = num_people;
        vector<int> ret(N, 0);
        int i = 0;
        while (candies) {
            int val = min(candies, i + 1);
            ret[i % N] += val;
            candies -= val;
            i = val;
        }
        return ret;
    }
};

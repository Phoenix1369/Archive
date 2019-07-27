const int MAXC = 5e6;

class Solution {
    vector<int> weights;
    int D;

public:
    int shipWithinDays(vector<int>& weights, int D) {
        this->weights = weights;
        this->D = D;
        int lo = 1;
        int hi = MAXC;
        while (lo < hi) {
            int x = (lo + hi) / 2;
            if (f(x)) {
                hi = x;
            } else {
                lo = x+1;
            }
        }
        return lo;
    }

private:
    bool f(int x) {
        int day = 0;
        int cargo = 0;
        for (int w: weights) {
            if (w > x) {
                return false;
            }
            if (cargo + w > x) {
                cargo = 0;
                ++day;
            }
            cargo += w;
        }
        return (day + 1 <= D);
    }
};

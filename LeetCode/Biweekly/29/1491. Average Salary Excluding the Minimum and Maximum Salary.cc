#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    double average(vector<int>& salary) {
        int N = salary.size();
        int mx = *max_element(ALL(salary));
        int mn = *min_element(ALL(salary));
        int sum = accumulate(ALL(salary), 0);
        return 1.0 * (sum - mx - mn) / (N-2);
    }
};

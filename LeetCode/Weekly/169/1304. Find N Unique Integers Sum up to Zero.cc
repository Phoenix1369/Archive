class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ret;
        if (n == 1) {
            ret.push_back(0);
            return ret;
        }
        for (int i = 1; i < n; ++i) {
            ret.push_back(i);
        }
        int val = sum(n-1);
        ret.push_back(-val);
        return ret;
    }

private:
    int sum(int n) {
        return n * (n + 1) / 2;
    }
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ret(n + 1, 0);
        for (auto book: bookings) {
            int i = book[0];
            int j = book[1];
            int k = book[2];
            ret[i-1] += k;
            ret[j] -= k;
        }
        for (int i = 1; i < n; ++i) {
            ret[i] += ret[i-1];
        }
        ret.pop_back();
        return ret;
    }
};

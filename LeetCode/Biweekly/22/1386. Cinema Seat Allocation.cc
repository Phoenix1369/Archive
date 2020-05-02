class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int M = reservedSeats.size();
        unordered_map<int,vector<int>> rows;
        rows.reserve(M);
        for (auto seat: reservedSeats) {
            int r = seat[0];
            int c = seat[1];
            rows[r].push_back(c);
        }
        int ret = 0;
        for (auto itr: rows) {
            ret += process_row(itr.second);
        }
        int R = rows.size();
        ret += 2 * (n - R);
        return ret;
    }

private:
    int process_row(vector<int> seats) {
        int lhs = 1;
        int mid = 1;
        int rhs = 1;
        for (int s: seats) {
            if ((2 <= s) && (s <= 5)) lhs = 0;
            if ((4 <= s) && (s <= 7)) mid = 0;
            if ((6 <= s) && (s <= 9)) rhs = 0;
        }
        return max(lhs + rhs, mid);
    }
};

template <typename T>
using vin = vector<T>;
const vin<vin<int>> NOPE = {};

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int C = 0;
        for (int c: colsum) C += c;
        int N = colsum.size();
        vin<int> A;
        vin<int> B;
        for (int c: colsum) {
            int a = 0;
            int b = 0;
            if ((c == 1) && (lower > upper)) {
                take(lower, c, b);
            }
            take(upper, c, a);
            take(lower, c, b);
            if (c) {
                return NOPE;
            }
            A.push_back(a);
            B.push_back(b);
        }
        if (upper || lower) {
            return NOPE;
        }
        return {A, B};
    }

private:
    void take(int& row, int& col, int& res) {
        if (col && row) {
            --row;
            --col;
            ++res;
        }
    }
};

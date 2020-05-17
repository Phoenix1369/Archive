class Solution {
public:
    vector<int> sumEvenAfterQueries(
            vector<int>& A,
            vector<vector<int>>& queries
    ) {
        int Q = queries.size();
        vector<int> ret;
        ret.reserve(Q);
        int sum = 0;
        for (int x: A) if ((x & 1) == 0) sum += x;
        for (auto query: queries) {
            int val = query[0];
            int index = query[1];
            if ((A[index] & 1) == 0) {
                sum -= A[index];
            }
            A[index] += val;
            if ((A[index] & 1) == 0) {
                sum += A[index];
            }
            ret.push_back(sum);
        }
        return ret;
    }
};

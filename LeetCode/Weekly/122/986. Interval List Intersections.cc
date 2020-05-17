class Solution {
public:
    vector<vector<int>> intervalIntersection(
            vector<vector<int>>& A,
            vector<vector<int>>& B
    ) {
        int N = A.size();
        int M = B.size();
        vector<vector<int>> ret;
        for (int i=0, j=0; (i < N) && (j < M); ) {
            while ((i < N) && (A[i][1] < B[j][0])) ++i;
            if (i >= N) break;
            while ((j < M) && (B[j][1] < A[i][0])) ++j;
            if (j >= M) break;
            if (B[j][0] > A[i][1]) continue;
            ret.push_back({
                max(A[i][0], B[j][0]),
                min(A[i][1], B[j][1])
            });
            if (A[i][1] > B[j][1]) {
                A[i][0] = B[j][1];
                ++j;
            } else if (B[j][1] > A[i][1]) {
                B[j][0] = A[i][1];
                ++i;
            } else {
                ++i;
                ++j;
            }
        }
        return ret;
    }
};

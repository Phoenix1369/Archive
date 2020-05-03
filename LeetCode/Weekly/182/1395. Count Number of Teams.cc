class Solution {
public:
    int numTeams(vector<int>& R) {
        int N = R.size();
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                if (R[i] != R[j]) {
                    for (int k = j+1; k < N; ++k) {
                        if (((R[i] < R[j]) && (R[j] < R[k])) ||
                            ((R[i] > R[j]) && (R[j] > R[k]))) ++ret;
                    }
                }
            }
        }
        return ret;
    }
};

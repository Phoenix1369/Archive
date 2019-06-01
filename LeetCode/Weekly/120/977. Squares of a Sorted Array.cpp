#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> B;
        for (int s: A) {
            B.push_back(s*s);
        }
        sort(ALL(B));
        return B;
    }
};

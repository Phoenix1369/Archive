vector<int> S;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        S.clear();
        int N = pushed.size();
        for (int i = 0, j = 0; i < N; ++i) {
            S.push_back(pushed[i]);
            while ((j < N) && !S.empty() && (S.back() == popped[j])) {
                S.pop_back();
                ++j;
            }
        }
        return S.empty();
    }
};

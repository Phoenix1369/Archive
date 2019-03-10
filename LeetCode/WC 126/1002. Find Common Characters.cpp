const int MAXN = 105;
std::map<char,int> cnt[MAXN];

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            cnt[i].clear();
            for (auto& c: A[i]) {
                ++cnt[i][c];
            }
        }
        vector<string> ret;
        for (char c = 'a'; c <= 'z'; ++c) {
            int sum = MAXN;
            for (int i = 0; i < N; ++i) {
                sum = std::min(cnt[i][c], sum);
            }
            for (int i = 0; i < sum; ++i) {
                ret.emplace_back(1, c);
            }
        }
        return ret;
    }
};
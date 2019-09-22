#define ALL(x) (x).begin(), (x).end()
set<string> seen;
int N;

class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        N = phrases.size();
        seen.clear();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                int a = phrases[i].rfind(' ');
                int b = phrases[j].find(' ');
                if (a == string::npos) a = -1;
                if (b == string::npos) b = phrases[j].size();
                if (phrases[i].compare(a + 1, string::npos, phrases[j], 0, b) == 0) {
                    seen.insert(phrases[i] + phrases[j].substr(b));
                }
            }
        }
        return vector<string>{ALL(seen)};
    }
};

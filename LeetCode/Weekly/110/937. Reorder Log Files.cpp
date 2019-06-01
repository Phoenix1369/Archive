#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(ALL(logs), [](const string& lhs, const string& rhs) {
            int lpos = lhs.find(' '); ++lpos;
            int rpos = rhs.find(' '); ++rpos;
            bool lalph = isalpha(lhs[lpos]);
            bool ralph = isalpha(rhs[rpos]);
            if (lalph != ralph) {
                return lalph;
            }
            if (!lalph) {
                // Digit-log
                return false;
            }
            // Letter-log
            int cmp = lhs.compare(
                lpos, string::npos, rhs,
                rpos, string::npos
            );
            if (cmp != 0) {
                return (cmp < 0);
            }
            return lhs.compare(rhs) < 0;
        });
        return logs;
    }
};


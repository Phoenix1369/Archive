const int MAXA = 26;
int ord[MAXA];

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int N = words.size();
        for (int i = 0; i < MAXA; ++i) {
            ord[order[i]-'a'] = i;
        }
        for (int i = 1; i < N; ++i) {
            if (!less(words[i-1], words[i])) {
                return false;
            }
        }
        return true;
    }

private:
    bool less(const string& lhs, const string& rhs) {
        int n = lhs.size();
        for (unsigned i = 0; i < n; ++i) {
            if (i >= rhs.size()) {
                return false;
            }
            if (lhs[i] != rhs[i]) {
                int a = ord[lhs[i]-'a'];
                int b = ord[rhs[i]-'a'];
                return (a < b);
            }
        }
        return true;
    }
};

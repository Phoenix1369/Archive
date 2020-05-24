class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss{sentence};
        string s;
        int M = searchWord.size();
        for (int i = 1; (iss >> s); ++i) {
            if (s.compare(0, M, searchWord) == 0) {
                return i;
            }
        }
        return -1;
    }
};

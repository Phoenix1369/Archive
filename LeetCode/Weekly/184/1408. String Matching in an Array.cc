class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int N = words.size();
        vector<string> ret;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                if (words[j].find(words[i]) != string::npos) {
                    ret.push_back(words[i]);
                    break;
                }
            }
        }
        return ret;
    }
};

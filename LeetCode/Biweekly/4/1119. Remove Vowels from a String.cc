const char * vowels = "aeiou";

class Solution {
public:
    string removeVowels(string S) {
        string ret;
        for (char c: S) {
            if (strchr(vowels, c) == nullptr) {
                ret.push_back(c);
            }
        }
        return ret;
    }
};

class Solution {
    string T;
public:
    string reverseOnlyLetters(string S) {
        int N = S.size();
        int a = N-1;
        T.clear();
        for (char c: S) {
            if (isalpha(c)) {
                while (!isalpha(S[a])) --a;
                T.push_back(S[a]);
                --a;
            } else {
                T.push_back(c);
            }
        }
        return T;
    }
};


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        process(S);
        process(T);
        return (S == T);
    }

private:
    void process(string& S) {
        int N = S.size();
        int tail = 0;
        for (int i = 0; i < N; ++i) {
            if (S[i] == '#') {
                if (tail > 0) --tail;
            } else {
                S[tail++] = S[i];
            }
        }
        S.erase(tail);
    }
};

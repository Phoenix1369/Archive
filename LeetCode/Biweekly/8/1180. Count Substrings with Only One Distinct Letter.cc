class Solution {
public:
    int countLetters(string S) {
        int N = S.size();
        int ret = 0;
        for (int i=0, j=0; i < N; i = j) {
            while ((j < N) && (S[j] == S[i])) ++j;
            ret += sum(j - i);
        }
        return ret;
    }

private:
    int sum(int n) {
        return n * (n + 1) / 2;
    }
};

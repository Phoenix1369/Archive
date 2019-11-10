const int MAXA = 26;
int cnt[MAXA];
int dnt[MAXA]{ };
vector<int> S;

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        S = move(score);
        int N = words.size();
        int L = 1 << N;
        int ret = 0;
        init(letters);
        for (int mask = 1; mask < L; ++mask) {
            int cur = 0;
            reset();
            for (int bit = 0; bit < N; ++bit) {
                if ((mask >> bit) & 1) {
                    for (char c: words[bit]) {
                        ++dnt[c-'a'];
                    }
                }
            }
            ret = max(compare(), ret);
        }
        return ret;
    }

private:
    int compare() {
        int sum = 0;
        for (int i = 0; i < MAXA; ++i) {
            if (dnt[i] > cnt[i]) {
                return 0;
            }
            sum += dnt[i] * S[i];
        }
        return sum;
    }

    void init(vector<char>& L) {
        for (int i = 0; i < MAXA; ++i) {
            cnt[i] = 0;
        }
        for (char c: L) {
            ++cnt[c-'a'];
        }
    }

    void reset() {
        for (int i = 0; i < MAXA; ++i) {
            dnt[i] = 0;
        }
    }
};

int cnt[3];

class Solution {
public:
    int numberOfSubstrings(string S) {
        int N = S.size();
        int ret = 0;
        cnt[0] = cnt[1] = cnt[2] = 0;
        
        int tail = 0;
        while (tail < N) {
            ++cnt[S[tail]-'a'];
            if (all3()) break;
            ++tail;
        }
        int head = 0;
        for (int i = tail; i < N; ++i) {
            if (i > tail) {
                ++cnt[S[i]-'a'];
            }
            while ((head < i) && all3()) {
                --cnt[S[head]-'a'];
                ++head;
            }
            ret += head;
        }
        return ret;
    }

private:
    bool all3() {
        return cnt[0] && cnt[1] && cnt[2];
    }
};

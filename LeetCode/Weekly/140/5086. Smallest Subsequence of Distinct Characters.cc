#define ALL(x) (x).begin(), (x).end()
const int MAXA = 26;
deque<int> cnt[MAXA];

class Solution {
public:
    string smallestSubsequence(string text) {
        int N = text.size();
        for (int i = 0; i < MAXA; ++i) {
            cnt[i].clear();
        }
        for (int i = 0; i < N; ++i) {
            cnt[text[i]-'a'].push_back(i);
        }
        string ret;
        bool done = false;
        while (!done) {
            done = true;
            for (int i = 0; i < MAXA; ++i) {
                if (cnt[i].empty() || !all_exists_after(i)) {
                    continue;
                }
                for (int j = 0; j < MAXA; ++j) {
                    if ((i == j) || cnt[j].empty()) {
                        continue;
                    }
                    while (!cnt[j].empty() && cnt[j].front() < cnt[i].front()) {
                        cnt[j].pop_front();
                    }
                }
                ret.push_back('a' + i);
                cnt[i].clear();
                done = false;
                break;
            }
        }
        return ret;
    }

private:
    bool all_exists_after(int i) {
        for (int j = 0; j < MAXA; ++j) {
            if ((i == j) || cnt[j].empty()) {
                continue;
            }
            auto ptr = lower_bound(ALL(cnt[j]), cnt[i].front());
            if (ptr == cnt[j].end()) {
                return false;
            }
        }
        return true;
    }
};

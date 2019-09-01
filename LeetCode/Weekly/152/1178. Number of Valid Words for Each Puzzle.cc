const int MAXA = 26;
const int MAXP = 1 << 7;
const int MAXS = 1 << MAXA;
int cnt[MAXS];

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        init();
        for (auto& w: words) {
            int mask = 0;
            for (char c: w) {
                mask |= 1 << (c - 'a');
            }
            ++cnt[mask];
        }
        
        vector<int> ans;
        for (auto& p: puzzles) {
            int ret = 0;
            for (int cur = 1; cur < MAXP; cur += 2) {
                // Mask on the indices of p:
                // * lowest bit is always set (odd)
                ret += cnt[translate(cur, p)];
            }
            ans.push_back(ret);
        }
        return ans;
    }

private:
    void init() {
        for (int i = 0; i < MAXS; ++i) {
            cnt[i] = 0;
        }
    }
    
    int translate(int mask, const string& p) {
        // mask: index -> characters
        int ret = 0;
        for (unsigned i = 0; i < p.size(); ++i) {
            if ((mask >> i) & 1) {
                ret |= 1 << (p[i] - 'a');
            }
        }
        return ret;
    }
};

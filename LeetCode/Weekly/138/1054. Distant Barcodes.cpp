unordered_map<int,int> cnt;

class Solution {
    vector<int> tmp, ret;
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int N = barcodes.size();

        // Counting Sort
        cnt.clear();
        cnt.reserve(N);
        for (int bc: barcodes) {
            ++cnt[bc];
        }

        // Interleave one of each type.
        tmp.clear();
        while (cnt.size() > 1u) {
            for (auto itr = cnt.begin(); itr != cnt.end();) {
                tmp.push_back(itr->first);
                if (!--itr->second) {
                    itr = cnt.erase(itr);
                } else {
                    ++itr;
                }
            }
        }

        // Splice remaining type into result.
        int T = tmp.size();
        ret.clear();
        for (int i = 0; i < T; ++i) {
            if (!cnt.empty()) {
                int val = cnt.begin()->first;
                if (i) {
                    if ((tmp[i-1] != val) && (tmp[i] != val)) {
                        push(val);
                    }
                } else if (tmp[i] != val) {
                    push(val);
                }
            }
            ret.push_back(tmp[i]);
        }
        if (!cnt.empty()) {
            ret.push_back(cnt.begin()->first);
        }

        return ret;
    }
private:
    void push(int val) {
        ret.push_back(val);
        if (!--cnt[val]) {
            cnt.erase(val);
        }
    }
};

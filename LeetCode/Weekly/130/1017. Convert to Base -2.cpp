const int LOGN = 32;

class Solution {
public:
    string baseNeg2(int N) {
        if (!N) return "0";
        vector<int> res(LOGN, 0);
        for (int i = 0, two = 1; two <= N; ++i, two <<= 1) if ((N >> i) & 1) {
            if (i & 1) {
                // Negative
                if (!res[i] && !res[i+1]) {
                    res[i] = res[i+1] = 1;
                } else if (!res[i]) {
                    // Assume !res[i+2]
                    res[i] = res[i+2] = 1;
                    res[i+1] = 0;
                } else {
                    res[i] = 0;
                }
            } else {
                // Positive
                if (res[i] && res[i+1]) {
                    res[i] = res[i+1] = 0;
                } else if (res[i]) {
                    // Assume !res[i+2]
                    res[i+1] = res[i+2] = 1;
                    res[i] = 0;
                } else {
                    res[i] = 1;
                }
            }
        }
        while (!res.empty() && !res.back()) {
            res.pop_back();
        }
        string ret;
        while (!res.empty()) {
            ret.push_back(res.back() + '0');
            res.pop_back();
        }
        return ret;
    }
};

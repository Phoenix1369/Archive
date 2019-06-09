const int MOD = 3;

class Solution {
    string data[MOD];
    vector<string> ret;
    int cnt, pos;

public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss{text};
        ret.clear();
        cnt = pos = 0;
        while (ss >> data[pos]) {
            int p1 = (pos + 1) % MOD;
            int p2 = (p1 + 1) % MOD;
            if (++cnt >= MOD) {
                if ((data[p1] == first) && (data[p2] == second)) {
                    ret.push_back(data[pos]);
                }
            }
            pos = p1;
        }
        return ret;
    }
};

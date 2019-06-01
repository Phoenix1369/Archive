#define ALL(x) (x).begin(), (x).end()
typedef vector<int> vin;

class Solution {
    int end, s, t;
    int cnt;

    vin ret;
public:
    vector<int> movesToStamp(string stamp, string target) {
        s = (int)stamp.size();
        t = (int)target.size();
        end = t-s;

        cnt = 0;
        while (cnt < t) {
            const int cpy = cnt;
            for (int i = 0; i <= end; ++i) {
                bool yes = true;
                bool mark = false;
                for (int j = 0; j < s; ++j) {
                    if ((target[i+j] != stamp[j]) && (target[i+j] != '?')) {
                        yes = false;
                        break;
                    }
                    if (target[i+j] != '?') {
                        mark = true;
                    }
                }
                if (yes && mark) {
                    remove(target, i);
                    i += s-1;
                }
            }
            if (cnt == cpy) {
                return {};
            }
        }
        reverse(ALL(ret));
        return ret;
    }
    
    void remove(string& target, int pos) {
        int last = pos + s;
        for (int i = pos; i < last; ++i) {
            if (target[i] != '?') {
                target[i] = '?';
                ++cnt;
            }
        }
        ret.push_back(pos);
    }
};

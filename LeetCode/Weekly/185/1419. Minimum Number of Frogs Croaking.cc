const int MAXK = 5;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int cnt[MAXK]{ };
        int ret = 0;
        int sum = 0;
        for (char c: croakOfFrogs) {
            int d = get(c);
            if (!d) {
                ++cnt[0];
                ++sum;
                ret = max(sum, ret);
                continue;
            }
            if (!cnt[d-1]) {
                return -1;
            }
            --cnt[d-1];
            if (d != 4) ++cnt[d];
            else --sum;
        }
        for (int k = 0; k < MAXK; ++k) {
            if (cnt[k]) return -1;
        }
        return ret;
    }

private:
    int get(char c) {
        switch (c) {
        case 'c': return 0;
        case 'r': return 1;
        case 'o': return 2;
        case 'a': return 3;
        case 'k': return 4;
        }
        return -1;
    }
};

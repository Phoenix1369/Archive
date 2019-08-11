const int DAYS[] = {
    31, 28, 31, 30, 31, 30, // JFMAMJ
    31, 31, 30, 31, 30, 31  // JASOND
};

class Solution {
    int D, M, Y;

public:
    int dayOfYear(string date) {
        sscanf(date.c_str(), "%4d-%d-%d", &Y, &M, &D);
        --M;

        int ret = 0;
        if (isleap(Y) && (M >= 2)) {
            ++ret;
        }
        for (int i = 0; i < M; ++i) {
            ret += DAYS[i];
        }
        ret += D;
        return ret;
    }

private:
    bool isleap(int yy) {
        return (yy % 4 == 0) && ((yy % 100 != 0) || (yy % 400 == 0));
    }
};

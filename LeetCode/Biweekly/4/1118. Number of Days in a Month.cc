const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

class Solution {
public:
    int numberOfDays(int Y, int M) {
        if (M != 2) {
            return days[M-1];
        }
        int leap = !(Y % 4) && (!(Y % 400) || (Y % 100));
        return days[M-1] + leap;
    }
};

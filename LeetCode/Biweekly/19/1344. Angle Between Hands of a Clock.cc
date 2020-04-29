const int DEG = 360 * 2;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        int H = (hour % 12) * 30 * 2 + minutes;
        int M = minutes * 6 * 2;
        return min_sub(H, M) / 2.0;
    }

private:
    int min_sub(int a, int b) {
        return min(sub(a, b), sub(b, a));
    }
    
    int sub(int a, int b) {
        return (a - b + DEG) % DEG;
    }
};

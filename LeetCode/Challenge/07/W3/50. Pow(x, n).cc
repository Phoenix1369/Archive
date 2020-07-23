class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            return 1.0 / fpm(x, -static_cast<unsigned>(n));
        }
        return fpm(x, n);
    }

private:
    template <typename T>
    T fpm(T b, unsigned n) {
        T p = 1;
        while (n) {
            if (n & 1) {
                p *= b;
            }
            b *= b;
            n >>= 1;
        }
        return p;
    }
};

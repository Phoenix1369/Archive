class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned a = 1u;
        unsigned b;
        while ((b = a * a) < num) ++a;
        return (b == num);
    }
};

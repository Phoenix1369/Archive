#include <algorithm>
#include <cmath>
#include <cstdio>
const double PI = acos(-1);
int A, B, X;

int main() {
    scanf(" %d%d%d", &A, &B, &X);
    int face = A*A;
    int volume = (face * B - X);
    double H = 2.0 * volume / face;
    if (H > B) {
        // The remaining water forms a triangle
        double K = 2.0 * X / A / B;
        double theta = atan2(K, B) / PI * 180.0;
        printf("%.9f\n", 90.0 - theta);
    } else {
        // The empty air forms a triangle
        double deg = atan2(H, A) / PI * 180.0;
        printf("%.9f\n", deg);
    }
    return 0;
}

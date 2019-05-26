#include <cstdio>
const int MAXI = 10;

int main() {
    int D, r, x;
    scanf(" %d%d%d", &r, &D, &x);
    for (int i = 0; i < MAXI; ++i) {
        x = r * x - D;
        printf("%d\n", x);
    }
    return 0;
}

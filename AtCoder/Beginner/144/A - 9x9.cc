#include <cstdio>
int A, B;

int main() {
    scanf(" %d%d", &A, &B);
    if ((A <= 9) && (B <= 9)) {
        printf("%d\n", A * B);
    } else {
        puts("-1");
    }
    return 0;
}

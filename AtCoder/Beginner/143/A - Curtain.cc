#include <algorithm>
#include <cstdio>
int A, B;

int main() {
    scanf(" %d%d", &A, &B);
    printf("%d\n", std::max(A - 2*B, 0));
    return 0;
}

#include <cstdio>
int A, B, C, D;

bool solve() {
  while (A > 0) {
    C -= B;
    if (C <= 0) {
      return true;
    }
    A -= D;
  }
  return false;
}

int main() {
  scanf(" %d%d%d%d", &A, &B, &C, &D);
  puts(solve() ? "Yes" : "No");
  return 0;
}

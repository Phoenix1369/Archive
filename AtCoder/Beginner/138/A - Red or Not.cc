#include <cstdio>
const int MAXS = 15;
char S[MAXS];
int A;

int main() {
  scanf(" %d%s", &A, S);
  puts((A < 3200) ? "red" : S);
  return 0;
}

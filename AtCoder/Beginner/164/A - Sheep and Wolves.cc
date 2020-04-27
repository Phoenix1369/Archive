#include <cstdio>
int S, W;

int main() {
  scanf(" %d%d", &S, &W);
  puts((W >= S) ? "unsafe" : "safe");
  return 0;
}

#include <cstdio>
char S[5];

int main() {
  scanf(" %s", S);
  S[1] ^= ('B' ^ 'R');
  puts(S);
  return 0;
}

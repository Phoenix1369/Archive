#include <algorithm>
#include <cstdio>
#include <cstring>
const int MAXK = 40320;
const int MAXN = 10;
char P[MAXK][MAXN];
char S[MAXN];
int K, N;

bool next_permutation() {
  // std::next_permutation practice
  int i = N-1;
  while ((i > 0) && (S[i-1] >= S[i])) --i;
  if (i == 0) {
    return false;
  }
  --i;
  int j = N-1;
  while (S[j] <= S[i]) --j;
  std::swap(S[j], S[i]);
  std::reverse(S+i+1, S+N);
  return true;
}

int main() {
  scanf(" %s", S);
  N = strlen(S);
  std::sort(S, S+N);
  K = 0;
  do {
    strcpy(P[K++], S);
  } while (next_permutation());
  printf("%d\n", K);
  for (int i = 0; i < K; ++i) {
    puts(P[i]);
  }
  return 0;
}

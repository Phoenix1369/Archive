#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
const int MAXS = 1e5+5;
const int NOPE = -1;
std::vector<int> dex[MAXS]{ };
char S[MAXS];
char T[MAXS];
int M, N;

lld solve() {
  for (int i = 0; i < N; ++i) {
    dex[S[i] - 'a'].push_back(i);
  }
  int pos = -1;
  lld ret = 0;
  for (int i = 0; i < M; ++i) {
    int c = T[i] - 'a';
    if (dex[c].empty()) {
      return NOPE;
    }
    auto ptr = std::upper_bound(ALL(dex[c]), pos);
    if (ptr == dex[c].end()) {
      ret += (N - pos) + dex[c].front();
      pos = dex[c].front();
    } else {
      ret += *ptr - pos;
      pos = *ptr;
    }
  }
  return ret;
}

int main() {
  scanf(" %s%s", S, T);
  N = strlen(S);
  M = strlen(T);
  printf("%lld\n", solve());
  return 0;
}

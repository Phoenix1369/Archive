#include <cstdio>
#include <cstring>
typedef long long lld;
const int BASE = 10;
const int MAXS = 2e5+5;
const int MOD = 2019;
int cnt[MOD];
char S[MAXS];
int ten[MAXS];
int N;

int main() {
  scanf(" %s", S+1);
  N = strlen(S+1);

  ten[0] = 1;
  for (int i = 1; i <= N; ++i) {
    ten[i] = 1LL * BASE * ten[i-1] % MOD;
  }

  for (int i = 0; i < MOD; ++i) {
    cnt[i] = 0;
  }
  cnt[0] = 1;

  lld ret = 0LL;
  int A = 0;
  for (int i = 1; i <= N; ++i) {
    A = (1LL * BASE * A + (S[i] - '0')) % MOD;

    int key = 1LL * ten[N-i] * A % MOD;
    ret += cnt[key];

    ++cnt[key];
  }
  printf("%lld\n", ret);
  return 0;
}

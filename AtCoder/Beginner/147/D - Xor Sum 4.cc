#include <cstdio>
typedef long long lld;
const int LOGN = 60;
const int MOD = 1e9+7;
int cnt[LOGN]{ };
lld A;
int N;

int main() {
  scanf("%d", &N);
  int ret = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%lld", &A);
    for (int j = 0; j < LOGN; ++j) {
      int two = (1LL << j) % MOD;
      int val;
      if ((A >> j) & 1) {
        val = 1LL * two * (i - cnt[j]) % MOD;
        ++cnt[j];
      } else {
        val = 1LL * two * cnt[j] % MOD;
      }
      ret = (1LL * ret + val) % MOD;
    }
  }
  printf("%d\n", ret);
  return 0;
}

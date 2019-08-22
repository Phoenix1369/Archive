#include <algorithm>
#include <cstdio>
#include <unordered_map>
typedef long long lld;
const int MAXS = 10;
std::unordered_map<std::string, int> cnt;
char S[MAXS + 5];
int N;

int main() {
  scanf("%d", &N);
  cnt.reserve(N);
  lld ret = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%s", S);
    std::sort(S, S + MAXS);
    ret += cnt[S]++;
  }
  printf("%lld\n", ret);
  return 0;
}

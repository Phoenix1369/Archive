#include <cstdio>
#include <unordered_map>
typedef long long lld;
const int MAXN = 2e5+5;
std::unordered_map<int,int> cnt;
int A[MAXN];
int N;

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
  }
  cnt.reserve(N);
  lld ret = 0LL;
  for (int i = 1; i <= N; ++i) {
    int key = i - A[i];
    if (cnt.count(key)) {
      ret += cnt.at(key);
    }
    ++cnt[A[i] + i];
  }
  printf("%lld\n", ret);
  return 0;
}

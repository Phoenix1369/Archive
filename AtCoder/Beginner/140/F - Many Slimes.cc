#include <algorithm>
#include <cstdio>
#include <set>
#define ALL(x) (x).begin(), (x).end()
const int MAXM = 3e5+5;
std::multiset<int> here, next, prev;
int M, N, S;

bool solve() {
  auto big = here.begin();
  next.insert(*big);
  here.erase(big);
  for (int i = 0; i < N; ++i) {
    prev = std::move(next);
    for (auto j: prev) {
      auto ptr = here.upper_bound(j);
      if (ptr == here.end()) {
        return false;
      }
      next.insert(*ptr);
      here.erase(ptr);
    }
    next.insert(ALL(prev));
  }
  return true;
}

int main() {
  scanf("%d", &N);
  M = 1 << N;
  for (int i = 0; i < M; ++i) {
    scanf("%d", &S);
    here.insert(-S);
  }
  puts(solve() ? "Yes" : "No");
  return 0;
}

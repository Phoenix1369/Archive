#include <cstdio>
#include <set>
std::multiset<int> tail;
int A, N;

// Greedily augment chain ending in largest value below A[i].

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A);
    auto ptr = tail.lower_bound(A);
    if (ptr != tail.begin()) {
      tail.erase(--ptr);
    }
    tail.insert(A);
  }
  printf("%u\n", tail.size());
  return 0;
}

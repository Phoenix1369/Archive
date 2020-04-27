#include <cstdio>
#include <string>
#include <unordered_set>
const int MAXS = 15;
std::unordered_set<std::string> seen;
char S[MAXS];
int N;

int main() {
  scanf("%d", &N);
  seen.clear();
  seen.reserve(N);
  for (int i = 0; i < N; ++i) {
    scanf(" %s", S);
    seen.insert(S);
  }
  printf("%lu\n", seen.size());
  return 0;
}

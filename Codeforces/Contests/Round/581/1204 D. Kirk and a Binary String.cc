#include <cstdio>
#include <cstring>
#include <vector>
const int MAXN = 1e5+5;
std::vector<int> S;
char B[MAXN];

int main() {
  scanf("%s", B);
  int N = strlen(B);
  for (int i = 0; i < N; ++i) {
    if (B[i] == '1') {
      S.push_back(i);
    } else if (!S.empty()) {
      S.pop_back();
    }
  }
  for (auto i: S) {
    B[i] = '0';
  }
  puts(B);
  return 0;
}

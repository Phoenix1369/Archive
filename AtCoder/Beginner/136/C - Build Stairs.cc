#include <cstdio>
#include <map>
const int MAXN = 1e5+5;
std::map<int,int> cnt;
int H[MAXN];
int N;

bool solve() {
  for (int i = 1; i < N; ++i) {
    if (!--cnt[H[i]]) {
      cnt.erase(H[i]);
    }
    int val = cnt.begin()->first;
    if (H[i]-1 > val) {
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%d", &N);
  cnt.clear();
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &H[i]);
    ++cnt[H[i]];
  }
  puts(solve() ? "Yes" : "No");
  return 0;
}

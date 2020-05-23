#include <algorithm>
#include <cstdio>
const int MAXN = 1e6+5;
char S[MAXN];
int N;

int sgn(int x) { return (x > 0) - (x < 0); }

struct Data {
  int dep, lvl;
  
  bool operator < (const Data& o) const {
    int dl = sgn(lvl);
    int dr = sgn(o.lvl);
    // +1 -> 0 -> -1
    if (dl != dr) return (dl > dr);
    // (dl == dr)
    if (dl >= 0) return (dep < o.dep);
    // (dl == -1)
    int suml = dep + lvl;
    int sumr = o.dep + o.lvl;
    if (suml != sumr) {
      return (suml > sumr);
    }
    // (suml == sumr)
    return (dep > o.dep);
  }
};
Data A[MAXN];

bool solve() {
  int lvl = 0;
  for (int i = 0; i < N; ++i) {
    if (lvl < A[i].dep) return false;
    lvl += A[i].lvl;
    if (lvl < 0) return false;
  }
  return (lvl == 0);
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf(" %s", S);
    int dep = 0;
    int lvl = 0;
    for (char *ptr = S; *ptr; ++ptr) {
      if (*ptr == '(') {
        ++lvl;
      } else {
        --lvl;
      }
      dep = std::min(lvl, dep);
    }
    A[i].dep = -dep;
    A[i].lvl = lvl;
  }
  std::sort(A, A+N);
  puts(solve() ? "Yes" : "No");
  return 0;
}

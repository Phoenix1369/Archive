#include <algorithm>
#include <cstdio>
#include <vector>
typedef long long lld;
const int MAXN = 1e5+5;
std::vector<int> S;
int h[MAXN];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &h[i]);
    }
    lld ret = 0;
    for (int i = 0; i < n; ++i) {
      while (!S.empty() && (h[i] <= h[S.back()])) {
        if ((int)S.size() >= 2) {
          ret = std::max(1LL * h[S.back()] * (i - S.end()[-2] - 1), ret);
        } else {
          ret = std::max(1LL * h[S.back()] * i, ret);
        }
        S.pop_back();
      }
      if (!S.empty()) {
        ret = std::max(1LL * h[i] * (i - S.back()), ret);
      } else {
        ret = std::max(1LL * h[i] * (i + 1), ret);
      }
      S.push_back(i);
    }
    while (!S.empty()) {
      ret = std::max(1LL * h[S.back()] * (n - S.back()), ret);
      S.pop_back();
    }
    printf("%lld\n", ret);
    return 0;
}

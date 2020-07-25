#include <iostream>
#include <string>
#include <unordered_set>
std::unordered_set<std::string> take;
std::string course;

void fastio() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

int main() {
  fastio();
  while (true) {
    int k, m;
    std::cin >> k;
    if (!k) {
      break;
    }
    std::cin >> m;
    take.clear();
    take.reserve(k);
    for (int i = 0; i < k; ++i) {
      std::cin >> course;
      take.insert(course);
    }
    bool req = true;
    for (int i = 0; i < m; ++i) {
      int c, r;
      std::cin >> c >> r;
      for (int j = 0; j < c; ++j) {
        std::cin >> course;
        if (take.count(course)) {
          --r;
        }
      }
      req &= (r <= 0);
    }
    std::cout << (req ? "yes" : "no") << '\n';
  }
  return 0;
}

#include <iostream>
int A1, A2, A3;

void fastio() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

int main() {
  fastio();
  std::cin >> A1 >> A2 >> A3;
  std::cout << (((A1 + A2 + A3) >= 22) ? "bust" : "win") << '\n';
  return 0;
}

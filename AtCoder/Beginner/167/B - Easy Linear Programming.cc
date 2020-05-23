#include <algorithm>
#include <cstdio>
#include <iostream>
int A, B, C, K;

void fastio() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

int main() {
  fastio();
  std::cin >> A >> B >> C >> K;
  std::cout << std::min(K, A) - std::min(std::max(K - A - B, 0), C) << '\n';
  return 0;
}

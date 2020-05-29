#include <iostream>
#include <string>
#include <unordered_map>
typedef std::string str;
const std::unordered_map<str, int> W = {
  {"SUN", 7}, {"MON", 6}, {"TUE", 5}, {"WED", 4},
  {"THU", 3}, {"FRI", 2}, {"SAT", 1}
};
str S;

void fastio() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

int main() {
  fastio();
  std::cin >> S;
  std::cout << W.at(S) << '\n';
  return 0;
}

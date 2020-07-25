#include <iostream>
#include <sstream>
#include <string>
const int MAXA = 26;
int wa[MAXA]{ };
std::string line;
std::string s;
char c;
int t;

void fastio() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

int main() {
  fastio();
  int solved = 0;
  int penalty = 0;
  while (true) {
    std::getline(std::cin, line);
    if (line[0] == '-') {
      break;
    }
    std::istringstream iss{line};
    iss >> c >> t >> s;
    int d = c-'A';
    if (s[0] == 'c') {
      penalty += t;
      penalty += wa[d];
      ++solved;
    } else {
      wa[d] += 20;
    }
  }
  std::cout << solved << ' ' << penalty << '\n';
  return 0;
}

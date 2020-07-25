#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
const int MAXS = 4;
const int MAXV = 13;
int size;
int n;

struct Card {
  int suit;
  int value;

  explicit Card(std::string s)
    : suit{getsuit(s.back())}
    , value{getvalue(s.end()[-2])} {}

private:
  int getsuit(char suit) {
    switch (suit) {
    case 'C': return 0;
    case 'D': return 1;
    case 'H': return 2;
    case 'S': return 3;
    }
    return 0;
  }

  int getvalue(char value) {
    switch (value) {
    case 'A': return 0;
    case '0': return 9;
    case 'J': return 10;
    case 'Q': return 11;
    case 'K': return 12;
    default : return value-'1';
    }
    return 0;
  }
};
std::vector<Card> hand;

struct Trie {
  std::unique_ptr<Trie> A[MAXS][MAXV];

  void insert(unsigned pos) {
    if (pos == hand.size()) {
      return;
    }
    int s = hand[pos].suit;
    int v = hand[pos].value;
    if (!A[s][v]) {
      A[s][v] = std::make_unique<Trie>();
      ++size;
    }
    return A[s][v]->insert(pos+1);
  }
};
std::unique_ptr<Trie> root;

void fastio() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

int main() {
  fastio();
  while (true) {
    root = std::make_unique<Trie>();
    size = 0;

    std::cin >> n;
    if (!n) {
      break;
    }
    for (int i = 0; i < n; ++i) {
      int m;
      std::cin >> m;
      hand.clear();
      for (int j = 0; j < m; ++j) {
        std::string s;
        std::cin >> s;
        hand.push_back(Card(s));
      }
      std::reverse(ALL(hand));
      root->insert(0);
    }
    std::cout << size << '\n';
  }
  return 0;
}

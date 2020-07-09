#include <cctype>
#include <cstdio>
#include <list>
const int MAXS = 1e6+5;
std::list<char> L;
char c;

int main() {
    auto ptr = L.begin();
    bool num = true;
    while ((c = getchar()) != EOF) {
        if (c == '<') {
            ptr = L.begin();
        } else if (c == '>') {
            ptr = L.end();
        } else if (c == '*') {
            if (ptr != L.begin()) {
                ptr = L.erase(--ptr);
            }
        } else if (c == '#') {
            num ^= true;
        } else {
            bool d = isdigit(c);
            if (!d || (d && num)) {
                ptr = L.insert(ptr, c);
                ++ptr;
            }
        }
    }
    for (char c: L) {
        putchar(c);
    }
    return 0;
}

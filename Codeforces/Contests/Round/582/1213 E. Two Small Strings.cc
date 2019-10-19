#include <algorithm>
#include <iostream>
#include <string>
#define ALL(x) (x).begin(), (x).end()
typedef std::string str;
const int MAXC = 5;
str output;
str S, T;
int N;

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

bool can_make_blocks() {
    bool self = (S[0] == S[1]) || (T[0] == T[1]);
    bool same = (S[0] == T[0]) || (S[1] == T[1]);
    bool circ = (S[0] == T[1]) && (S[1] == T[0]);
    return !self && (same || circ);
}

bool matches(const str& s) {
    return (s.compare(S) == 0) || (s.compare(T) == 0);
}

bool is_valid(str perm, bool roll) {
    if (roll) {
        perm += perm[0];
    }
    int sz = perm.size();
    for (int i = 0; i+1 < sz; ++i) {
        if (matches(perm.substr(i, 2))) {
            return false;
        }
    }
    return true;
}

void permute(str& P, bool roll) {
    do {
        if (is_valid(P, roll)) break;
    } while (std::next_permutation(ALL(P)));
}

void loop(const str& s) {
    for (char c: s) {
        for (int i = 0; i < N; ++i) {
            output.push_back(c);
        }
    }
}

void roll(const str& s) {
    for (int i = 0; i < N; ++i) {
        for (char c: s) {
            output.push_back(c);
        }
    }
}

void solve() {
    str P = "abc";
    bool B = can_make_blocks();
    permute(P, !B);
    if (B) {
        loop(P);
    } else {
        roll(P);
    }
}

int main() {
    fast_io();
    std::cin >> N >> S >> T;
    output.reserve(3 * N);
    solve();
    std::cout << "YES\n" << output << std::endl;
    return 0;
}

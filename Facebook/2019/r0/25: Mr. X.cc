#include <cstdio>
#include <cstring>
#include <vector>
#define PROBLEM "mr_x"
const int MAXE = 305;
std::vector<char> S;
char E[MAXE];
int N, T;

char eval_and(char A, char B) {
    if (A == B) {
        return A;
    }
    if (A == '0') {
        return '0';
    }
    if (A == '1') {
        return B;
    }
    return '0';
}   // (A < B) -> (A, B) = (X, x)

char eval_or(char A, char B) {
    if (A == B) {
        return A;
    }
    if (A == '0') {
        return B;
    }
    if (A == '1') {
        return '1';
    }
    return '1';
}   // (A < B) -> (A, B) = (X, x)

char eval_xor(char A, char B) {
    if (A == B) {
        return '0';
    }
    if (A == '0') {
        return B;
    }
    if (A == '1') {
        return B ^ ('X' ^ 'x');
    }
    return '1';
}   // (A < B) -> (A, B) = (X, x)

char eval(char A, char op, char B) {
    if (A > B) std::swap(A, B);
    switch (op) {
    case '&':
        return eval_and(A, B);
    case '|':
        return eval_or(A, B);
    }
    return eval_xor(A, B);
}   // (op == '^')

int solve() {
    N = strlen(E + 1);
    S.clear();

    if (N == 1) {
        S.push_back(E[1]);
    }

    for (int i = 1; i <= N; ++i) {
        if (E[i] != ')') {
            if (E[i] != '(') {
                S.push_back(E[i]);
            }
            continue;
        }
        char B = S.back(); S.pop_back();
        char op= S.back(); S.pop_back();
        char A = S.back(); S.pop_back();
        S.push_back(eval(A, op, B));
    }
    return S.back() <= '1' ? 0 : 1;
}

int main() {
//    freopen(PROBLEM "_sample_input.txt", "r", stdin);
    freopen(PROBLEM ".txt", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf(" %s", E + 1);
        printf("Case #%d: %d\n", t, solve());
    }
    return 0;
}


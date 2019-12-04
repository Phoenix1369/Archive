#include <cstdio>
#include <stack>
#include <vector>
const int MAXN = 2e5+5;
const int NOPE = -1;
std::stack<int> S;
std::vector<int> A;
std::vector<int> ret;
int N;

int main() {
    scanf("%d", &N);
    A.reserve(N);
    ret.assign(N, -1);
    for (int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        A.push_back(x);
    }
    for (int i = 0; i < N; ++i) {
        while (!S.empty() && (A[i] < A[S.top()])) {
            ret[S.top()] = i;
            S.pop();
        }
        S.push(i);
    }
    for (int& x: ret) {
        printf("%d ", x);
    }
    putchar('\n');
    return 0;
}

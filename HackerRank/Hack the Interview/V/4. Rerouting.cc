#include <cstdio>
const int MAXN = 3e5+5;
bool seen[MAXN]{ };
int A[MAXN];
int N;

// Union-Find Disjoint Set
int cycle;
int total;

int find(int u) {
    int v = u;
    while (v != A[v]) {
        if (seen[A[v]]) {
            A[v] = v;
            ++cycle;
            break;
        }
        seen[v] = true;
        v = A[v];
    }
    while (u != v) {
        seen[u] = false;
        int w = A[u];
        A[u] = v;
        u = w;
    }
    return u;
}

// (cycle <  total) -> point other components to an existing sink node
// (cycle == total) -> break some cycle to form a sink node

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }
    cycle = 0;
    total = 0;
    for (int i = 1; i <= N; ++i) {
        if (i == find(i)) ++total;
    }
    if (cycle < total) {
        --total;
    }
    printf("%d\n", total);
    return 0;
}

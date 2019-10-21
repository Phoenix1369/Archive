#include <cstdio>
#include <vector>
const int MAXN = 5005;
std::vector<int> G[MAXN];
bool active[MAXN];
bool seen[MAXN];
int K, M, N;

struct Edge {
    int v, w;
} E[MAXN];
enum { TREE=1, BACK };

void init() {
    for (int i = 1; i <= N; ++i) {
        active[i] = false;
        seen[i] = false;
    }
    K = TREE;
}

void dfs(int cur) {
    seen[cur] = true;
    active[cur] = true;
    for (int i: G[cur]) {
        int nxt = E[i].v;
        if (active[nxt]) {
            K = BACK;
            E[i].w = BACK;
        } else {
            E[i].w = TREE;
            if (!seen[nxt]) {
                dfs(nxt);
            }
        }
    }
    active[cur] = false;
}

void display() {
    printf("%d\n", K);
    for (int i = 0; i < M; ++i) {
        printf("%d ", E[i].w);
    }
    putchar('\n');
}

int main() {
    scanf(" %d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int u;
        scanf(" %d%d", &u, &E[i].v);
        G[u].push_back(i);
    }
    init();
    for (int i = 1; i <= N; ++i) {
        if (seen[i]) continue;
        dfs(i);
    }
    display();
    return 0;
}

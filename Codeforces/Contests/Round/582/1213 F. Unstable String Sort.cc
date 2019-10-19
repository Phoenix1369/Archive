#include <cstdio>
#include <vector>
const int MAXN = 2e5+5;
int G[MAXN];
int P[MAXN];
int Pinv[MAXN];
bool seen[MAXN];
std::vector<int> start;
char output[MAXN];
int K, N, Q;
int prev;
int M;

void init() {
    prev = 0;
    for (int i = 1; i <= N; ++i) {
        seen[i] = false;
    }
}

void solve() {
    for (int i = 1; i <= N; ++i) {
        int cur = P[i];
        int nxt = G[cur];
        seen[cur] = true;
        if (!seen[nxt]) {
            start.push_back(i);
            continue;
        }
        // Back-edge
        while (!start.empty() && (start.back() > Pinv[nxt])) {
            start.pop_back();
        }
    }
    M = start.size();
}

void display() {
    char c = 'a';
    --c;
    for (int i=1, j=0; i <= N; ++i) {
        if ((j < M) && (c < 'z') && (i == start[j])) {
            ++c;
            ++j;
        }
        output[P[i]] = c;
    }
    output[N+1] = '\0';
    puts(output+1);
}

int main() {
    scanf(" %d%d", &N, &K);
    init();
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &P[i]);
        Pinv[P[i]] = i;
    }
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &Q);
        G[prev] = Q;
        prev = Q;
    }
    solve();
    if (M >= K) {
        puts("YES");
        display();
    } else {
        puts("NO");
    }
    return 0;
}

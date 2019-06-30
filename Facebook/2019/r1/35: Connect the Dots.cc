#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
#define PROBLEM "connect_the_dots"
#define SOLVE
const int INFN = 1e9+7;
const int MAXN = 8e5+5;
int X[MAXN], Y[MAXN];
int Ax[4], Ay[4];
int H, N, T, V;

std::vector<int> order;
int suffmax[MAXN];

// Priority Queue
template <typename T, typename C>
using heap = std::priority_queue<T, std::vector<T>, C>;

struct CMPmaxY {
    bool operator () (int lhs, int rhs) const {
        return Y[lhs] < Y[rhs];
    }   // max-heap on Y-coordinate
};
struct CMPminY {
    bool operator () (int lhs, int rhs) const {
        return Y[rhs] < Y[lhs];
    }   // min-heap on Y-coordinate
};
heap<int, CMPmaxY> pqmax;
heap<int, CMPminY> pqmin;

template <typename T>
void qclear(T& pq) {
    T().swap(pq);
}

int solve() {
    if (H + V < N) {
        return -1;
    }

    // Sort points by (x, y)
    order.clear();
    order.reserve(N);
    for (int i = 1; i <= N; ++i) {
        order.push_back(i);
    }
    std::sort(ALL(order), [](int lhs, int rhs) {
        return (X[lhs] != X[rhs]) ? (X[lhs] < X[rhs]) : (Y[lhs] < Y[rhs]);
    });

    // Prefix maximum on Y-coordinate
    suffmax[N] = 0;
    for (int i = N-1; i >= 0; --i) {
        suffmax[i] = std::max(Y[order[i]], suffmax[i+1]);
    }

    int ret = INFN*2;
    if (V == N) {
        ret = suffmax[0];
    }
    int head = 0;
    const unsigned HH = H;
    qclear(pqmax);
    qclear(pqmin);
    while (head < N) {
        int tail = head;
        while ((tail < N) && (X[order[head]] == X[order[tail]])) {
            pqmin.push(order[tail]);
            ++tail;
        }
        while (pqmin.size() > HH) {
            pqmax.push(pqmin.top());
            pqmin.pop();
        }
        if (!pqmax.empty()) {
            ret = std::min(X[order[head]] + std::max(Y[pqmax.top()], suffmax[tail]), ret);
        } else if (N - tail <= V) {
            ret = std::min(X[order[head]] + suffmax[tail], ret);
        }   // All points covered by horizontal lines
        head = tail;
    }
    return ret;
}

// Iterate on max X-coordinate for horizontals in O(H).
// Remove the H points covered, with the highest Y-coordinates.
// Compute maximal remaining Y-coordinate and satisfy <= H and <= V.

void generate(int* a, int* b) {
    for (int i = 3; i <= N; ++i) {
        int aa = 1LL * b[0] * a[i-2] % b[3];
        int bb = 1LL * b[1] * a[i-1] % b[3];
        a[i] = (((aa + bb) % b[3] + b[2]) % b[3]) + 1;
    }
}

int main() {
#ifndef SOLVE
    freopen(PROBLEM "_sample_input.txt", "r", stdin);
#else
    freopen(PROBLEM ".txt", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
#endif
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf(" %d%d%d", &N, &H, &V);
        scanf(" %d%d", &X[1], &X[2]);
        for (int i = 0; i < 4; ++i) scanf("%d", &Ax[i]);
        scanf(" %d%d", &Y[1], &Y[2]);
        for (int i = 0; i < 4; ++i) scanf("%d", &Ay[i]);
        generate(X, Ax);
        generate(Y, Ay);
        printf("Case #%d: %d\n", t, solve());
    }
    return 0;
}

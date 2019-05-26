#include <cstdio>
#include <functional>
#include <queue>
#include <vector>
typedef long long lld;
typedef std::priority_queue<int> max_heap;
typedef std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
max_heap mxh;
min_heap mnh;
int a, b, Q;
lld A, B;

// mxh: [3, 2, 1]
// mnh: [5, 8, D]
// mxh.top <= mnh.top

void update() {
    B += b;
    // Insertion
    if (mxh.empty()) {
        mxh.push(a);
    } else if (a <= mxh.top()) {
        A += mxh.top() - a;
        mxh.push(a);
    } else {
        A += a - mxh.top();
        mnh.push(a);
    }
    // Rotations
    while (mxh.size() >= (mnh.size() + 2u)) {
        mnh.push(mxh.top());
        mxh.pop();
        A -= 1LL * (mnh.top() - mxh.top()) * (mxh.size() - mnh.size());
    }
    while (mnh.size() > mxh.size()) {
        A -= 1LL * (mnh.top() - mxh.top()) * (mnh.size() - mxh.size());
        mxh.push(mnh.top());
        mnh.pop();
    }
}

int query() { return mxh.top(); }

int main() {
    scanf("%d", &Q);
    A = B = 0LL;
    for (int q = 1; q <= Q; ++q) {
        char cmd;
        scanf(" %c", &cmd);
        switch (cmd) {
        case '1':
            scanf(" %d%d", &a, &b);
            update();
            break;
        case '2':
            printf("%d %lld\n", query(), A + B);
            break;
        }
    }
    return 0;
}

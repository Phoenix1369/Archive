#include <cstdio>
#include <cstring>
#define PROBLEM "leapfrog_ch_"
const int MAXN = 5005;
char lily[MAXN];
int T;

int main() {
//    freopen(PROBLEM "_sample_input.txt", "r", stdin);
    freopen(PROBLEM ".txt", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf(" %s", lily);
        int N = strlen(lily);
        int beta = 0;
        int free = 0;
        for (int i = 1; i < N; ++i) {
            if (lily[i] == 'B') {
                ++beta;
            } else {
                ++free;
            }
        }
		bool yes = (beta >= 1) && (free >= 1) && ((beta >= 2) || (free == 1));
        printf("Case #%d: %c\n", t, yes ? 'Y' : 'N');
    }
    return 0;
}

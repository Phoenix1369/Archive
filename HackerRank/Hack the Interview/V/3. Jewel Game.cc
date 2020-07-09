#include <cstdio>
#include <vector>
std::vector<int> S;
int ret, T;
char c;

int main() {
    scanf("%d\n", &T);
    for (int t = 0; t < T; ++t) {
        S.clear();
        ret = 0;
        while ((c = getchar()) != '\n') {
            if (!S.empty() && (c == S.back())) {
                S.pop_back();
                ++ret;
            } else {
                S.push_back(c);
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}

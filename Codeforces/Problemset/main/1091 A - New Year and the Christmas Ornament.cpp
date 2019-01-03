#include <algorithm>
#include <cstdio>
int b, r, y;

int main() {
	scanf(" %d%d%d", &y, &b, &r);
	printf("%d\n", std::min(y+1, std::min(b, r-1)) * 3);
	return 0;
}

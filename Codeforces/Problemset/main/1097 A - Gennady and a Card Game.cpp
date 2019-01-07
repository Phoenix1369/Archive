#include <cstdio>
const int MAXC = 9;
char card[MAXC], hand[MAXC];

bool solve() {
	scanf(" %s", card);
	for (int i = 0; i < 5; ++i) {
		scanf(" %s", hand);
		for (int j = 0; j < 2; ++j) {
			if (hand[j] == card[j]) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	puts(solve() ? "YES" : "NO");
	return 0;
}

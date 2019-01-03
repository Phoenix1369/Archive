#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 1e5+5;
enum { GRASS = 'G', WATER = 'W', LAVA = 'L' };
enum { G = 5, W = 3, L = 1 };
lld a[MAXN];
char s[MAXN];
int n;

bool water;
lld grass, stamina, t;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	scanf(" %s", s);
	water = false;
	grass = stamina = t = 0LL;
	for (int i = 0; i < n; ++i) {
		switch (s[i]) {
		case GRASS:
			grass += 2*a[i];
			stamina += 2*a[i];
			grass = std::min(stamina / 2, grass);
			t += G*a[i];
			break;
		case WATER:
			water = true;
			stamina += 2*a[i];
			t += W*a[i];
			break;
		case LAVA:
			if (stamina < 2*a[i]) {
				t += ((water) ? W : G) * (a[i] - stamina / 2);
				stamina = 0;
			} else {
				stamina -= 2*a[i];
			}
			t += L*a[i];
			grass = std::min(stamina / 2, grass);
			break;
		}
	}
	t -= (G-L)/2*grass;
	t -= (W-L)/2*(stamina / 2 - grass);
	printf("%lld\n", t);
	return 0;
}

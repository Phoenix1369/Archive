#include <cstdio>
const int MAXA = 180;
const int MAXN = 360;
int N[MAXA];
int T;

void polygon() {
	for (int n = 0; n <= MAXN; ++n) {
		N[n] = -1;
	}
	for (int n = 3; n <= MAXN; ++n) {
		for (int k = 3; k <= n; ++k) {
			/**(k-gon - (k-2) n-regular) / 2
			 * [180(k-2) - (k-2)180(n-2)/n] / 2
			 * 90(k-2)(1 - (n-2)/n)
			 */
			int kgon = 180*(k-2);
			int nreg = kgon*(n-2);
			if (nreg % n) continue;
			nreg /= n;
			int ngon = kgon - nreg;
			if (ngon % 2) continue;
			ngon /= 2;
			if (N[ngon] == -1) {
				N[ngon] = n;
			}
		}
	}
}

int main() {
	polygon();
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int ang;
		scanf("%d", &ang);
		printf("%d\n", N[ang]);
	}
	return 0;
}

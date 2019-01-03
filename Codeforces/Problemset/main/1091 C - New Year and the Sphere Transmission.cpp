#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
typedef std::vector<lld> vin;
vin f;
int n;

int main() {
	scanf("%d", &n);
	int sn = sqrt(n);
	for (int i = 1; i <= sn; ++i) if ((n % i) == 0) {
		int j = n / i;
		f.push_back(1LL*i*(j-1)*j/2 + j);
		if (j == i) continue;
		f.push_back(1LL*j*(i-1)*i/2 + i);
	}
	std::sort(ALL(f));
	f.erase(unique(ALL(f)), f.end());
	for (auto i: f) {
		printf("%lld ", i);
	}
	return 0;
}

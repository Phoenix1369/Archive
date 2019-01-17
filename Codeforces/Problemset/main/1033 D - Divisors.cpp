#include <cmath>
#include <cstdio>
#include <map>
typedef long long lld;
const int MAXN = 505;
const int MOD = 998244353;
std::map<lld,int> p, semi;
bool done[MAXN];
lld a[MAXN];
int n;

template <typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <typename T> T sqrmod(T x) { return 1LL*x*x % MOD; }

bool check(const lld& num) {
	lld s2 = sqrtl(num);
	if (s2*s2 == num) {
		lld s4 = sqrtl(s2);
		if (s4*s4 == s2) {
			p[s4] += 4;
		} else {
			p[s2] += 2;
		}
		return true;
	}

	lld s3 = cbrtl(num);
	if (s3*s3*s3 == num) {
		p[s3] += 3;
		return true;
	}
	return false;
}

void finish(int i, const lld& g) {
	if (done[i]) return;
	++p[g];
	++p[a[i]/g];
	done[i] = true;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
		done[i] = check(a[i]);
		for (int j = 0; j < i; ++j) if (a[j] != a[i]) {
			lld g = gcd(a[i], a[j]);
			if (g == 1LL) continue;
			finish(i, g);
			finish(j, g);
		}
	}
	int ret = 1;
	for (auto itr: p) {
		ret = 1LL*(itr.second+1)*ret % MOD;
	}
	for (int i = 0; i < n; ++i) if (!done[i]) {
		++semi[a[i]];
	}	// Semi-primes: unique divisors
	for (auto itr: semi) {
		ret = 1LL*sqrmod(itr.second+1)*ret % MOD;
	}
	printf("%d\n", ret);
	return 0;
}
// 3: n=a^2	[1,a,a^2]
// 4: n=ab	[1,a,b,ab]
//  : n=a^3	[1,a,a^2,a^3]
// 5: n=a^4	[1,a,a^2,a^3,a^4]

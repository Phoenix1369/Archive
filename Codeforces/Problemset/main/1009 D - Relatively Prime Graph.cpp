#include <cstdio>
#include <utility>
#include <vector>
#define x first
#define y second
typedef long long lld;
typedef std::pair<int,int> pii;
typedef std::vector<pii> vip;
const int MAXN = 1E5+5;
int m, n;
vip out;

template <typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

bool solve()
{
	if(m < n-1)
		return false; // Connected
	for(int i = 2; i <= n; ++i)
		out.emplace_back(1, i);
	int sum = (int)out.size();
	if(sum == m)
		return true;
	for(int i = 2; i <= n; ++i)
	for(int k = 1; k < i; ++k) if(gcd(i, k) == 1)
	for(int j = 1; (i*j+k) <= n; ++j)
	{
		out.emplace_back(i, i*j+k);
		if(++sum == m)
			return true;
	}
	return false;
}

int main()
{
	scanf(" %d%d", &n, &m);
	bool ret = solve();
	puts(ret ? "Possible" : "Impossible");
	if(ret)
		for(auto edge: out)
			printf("%d %d\n", edge.x, edge.y);
    return 0;
}
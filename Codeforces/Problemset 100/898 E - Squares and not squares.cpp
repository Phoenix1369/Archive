#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
typedef std::vector<int> vin;
vin candy[2]{ };
lld ret=0LL;
int A, N;

int f(int num)
{
	int s = sqrt(num);
	return std::min(num-s*s, (s+1)*(s+1)-num);
}

int g(int num) { return num ? 1 : 2; }

void split(int k, int (*fun)(int))
{
	ret += fun(candy[k].back());
	candy[k^1].push_back(candy[k].back());
	candy[k].pop_back();
}

int main()
{
	scanf("%d", &N);
	for(int j = 0; j < 2; ++j)
		candy[j].reserve(N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A);
		int S = sqrt(A);
		candy[S*S==A].push_back(A);
	}
	std::sort(ALL(candy[0]), [&](const int& l, const int& r) {
		return f(l) > f(r);
	});
	std::sort(ALL(candy[1]), [&](const int& l, const int& r) {
		return g(l) > g(r);
	});
	while(candy[0].size() > candy[1].size())
		split(0, f); // Non->Square
	while(candy[1].size() > candy[0].size())
		split(1, g); // Square->Non
	printf("%lld\n", ret);
	return 0;
}
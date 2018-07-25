#include <algorithm>
#include <cstdio>
#include <unordered_map>
const int MAXN = 1e5+5;
std::unordered_map<int,int> cnt;
int a[MAXN]{ };
int m=1e9, n;

int main()
{
	scanf("%d", &n);
	cnt.reserve(n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		++cnt[a[i]];
	}
	std::sort(a, a+n);
	int bank=cnt.at(a[0]), ret=0;
	for(int i = 1; i < n; ++i) if(a[i] != a[i-1])
	{
		int diff = std::min(bank, cnt.at(a[i]));
		bank += cnt.at(a[i])-diff;
		ret += diff;
	}
	printf("%d\n", ret);
    return 0;
}

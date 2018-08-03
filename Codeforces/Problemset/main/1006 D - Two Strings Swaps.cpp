#include <cstdio>
#include <map>
const int MAXN = 1e5+5;
std::map<char,int> cnt;
char a[MAXN], b[MAXN];
int n, ret=0;

int main()
{
	scanf(" %d%s%s", &n, a, b);
	for(int i = 0; i*2 < n; ++i)
	{
		++cnt[a[i]];
		++cnt[b[i]];
		if(i != n-i-1)
		{
			++cnt[a[n-i-1]];
			++cnt[b[n-i-1]];
		}
		if(cnt.size() == 4U)
			ret += 2;
		else if(cnt.size() == 3U)
		{
			if(a[i] == a[n-i-1])
				ret += 2;
			else
				++ret;
		}
		else if(cnt.size() == 2U)
		{
			if(i*2+1 == n)
				++ret;
			else if(cnt.begin()->second != 2)
				++ret;
		}
		cnt.clear();
	}
	printf("%d\n", ret);
	return 0;
}
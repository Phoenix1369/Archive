#include <cstdio>
#include <cstring>
typedef long long lld;
char buff[15];
lld ans=0;

int main()
{
	scanf(" %s", buff);
	int L = strlen(buff);
	int lim = 1 << (L-1);
	for(int mask = 0; mask < lim; ++mask)
	{
		lld sum = 0LL;
		for(int bit = 0; bit < L; ++bit)
		{
			sum = sum*10LL + buff[bit]-'0';
			if((mask >> bit) & 1)
			{
				ans += sum;
				sum = 0;
			}
		}
		ans += sum;
	}
	printf("%lld\n", ans);
	return 0;
}
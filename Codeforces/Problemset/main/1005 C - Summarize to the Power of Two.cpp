#include <cstdio>
#include <unordered_map>
#define x first
#define y second
std::unordered_map<int,int> cnt;
int a, n, ret=0;

int main()
{
	scanf("%d", &n);
	cnt.reserve(n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		++cnt[a];
	}
	for(auto itr: cnt)
	{
		bool yes = false;
		for(int i=1, j=2; !yes && (i <= 30); ++i, j <<= 1)
			if(j > itr.x)
			{
				int oth = j - itr.x;
				if(itr.x == oth)
					yes |= (itr.y > 1);
				else
					yes |= cnt.count(oth);
			}
		if(!yes)
			ret += itr.y;
	}
	printf("%d\n", ret);
    return 0;
}
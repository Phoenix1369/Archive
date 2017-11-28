#include <cstdio>
#include <map>
std::map<int,int> cnt[2]{ };
int N, num;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{	// A := a1, a2, ..., an
		scanf("%d", &num);
		++cnt[0][num];
	}
	for(int i = 1; i < N; ++i)
	{	// B := b1, b2, ..., bn
		scanf("%d", &num);
		if(!--cnt[0][num])
			cnt[0].erase(num);
		++cnt[1][num];
	}
	printf("%d\n", cnt[0].begin()->first);
	for(int i = 2; i < N; ++i)
	{	// C := c1, c2, ..., cn
		scanf("%d", &num);
		if(!--cnt[1][num])
			cnt[1].erase(num);
	}
	printf("%d\n", cnt[1].begin()->first);
	return 0;
}
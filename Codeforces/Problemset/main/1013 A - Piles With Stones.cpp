#include <cstdio>
int cnt[2], n, x;

int main()
{
	scanf("%d", &n);
	cnt[0]=cnt[1]=0;
	for(int i = 0; i < 2; ++i)
	for(int j = 0; j < n; ++j)
	{
		scanf("%d", &x);
		cnt[i] += x;
	}
	puts((cnt[0] >= cnt[1]) ? "Yes" : "No");
	return 0;
}

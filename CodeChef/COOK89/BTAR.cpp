#include <cstdio>
int cnt[4]{ };
int A, N, T;

int main()
{
	scanf("%d", &T);
	for(int _ = 0; _ < T; ++_)
	{
		scanf("%d", &N);
		for(int i = 0; i < 4; ++i)
			cnt[i] = 0;
		for(int i = 0; i < N; ++i)
		{
			scanf("%d", &A);
			++cnt[A&3];
		}
		int ret = 0;
		while(cnt[2] && (cnt[1] > cnt[3]))
			--cnt[1], --cnt[2], ++cnt[3], ++ret;
		while(cnt[2] && (cnt[3] > cnt[1]))
			++cnt[1], --cnt[2], --cnt[3], ++ret;
		if((cnt[1] == cnt[3]) && !(cnt[2] & 1))
			printf("%d\n", cnt[1] + cnt[2]/2 + ret);
		else
			puts("-1");
	}
	return 0;
}
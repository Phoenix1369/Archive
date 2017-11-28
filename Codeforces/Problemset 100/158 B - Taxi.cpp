#include <algorithm>
#include <cstdio>
int cnt[5]{ };
int N, ret;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		int num;
		scanf("%d", &num);
		++cnt[num];
	}
	// Greedily Pair off 2s
	ret = cnt[4] + (cnt[2] / 2);
	cnt[2] &= 1;
	if(cnt[2] && cnt[1])
		cnt[1] -= std::min(2, cnt[1]);
	// Combine 1s and 3s
	int one_thr = std::min(cnt[1], cnt[3]);
	cnt[1] -= one_thr;
	cnt[3] -= one_thr;
	ret += cnt[3] + cnt[2] + one_thr + ((cnt[1] + 3) / 4);
	printf("%d\n", ret);
	return 0;
}

#include <algorithm>
#include <cstdio>
#define CODE "lazy_loading"
const int MAXN = 105;
int array[MAXN]{ };
int C, head, K, N, T, tail;

int main()
{
	freopen(CODE ".txt", "r", stdin);
	freopen(CODE ".out", "w", stdout);
	scanf("%d", &T);
	for(int _ = 1; _ <= T; ++_)
	{
		scanf("%d", &N);
		for(int i = 1; i <= N; ++i)
			scanf("%d", &array[i]);
		std::sort(array+1, array+N+1);
		C=0, head=1, tail=N;
		while(head <= tail)
		{
			K = 1;
			while(head < tail)
			{
				if(K * array[tail] >= 50)
					break;
				++head;
				++K;
			}
			if(K * array[tail] < 50)
				break;
			--tail;
			C++; // Language!
		}
		printf("Case #%d: %d\n", _, C);
	}
	return 0;
}
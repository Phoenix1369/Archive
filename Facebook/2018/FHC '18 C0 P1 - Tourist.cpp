#include <cstdio>
#define CODE "tourist"
typedef long long lld;
const int MAXN = 55;
char lieu[MAXN][MAXN]{ };
int K, N, T;
lld V;

int main()
{
	// freopen(CODE "_example_input.txt", "r", stdin);
	// freopen(CODE "_example_output.txt", "w", stdout);
	freopen(CODE ".txt", "r", stdin);
	freopen(CODE ".out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		scanf(" %d%d%lld", &N, &K, &V);
		for(int i = 0; i < N; ++i)
			scanf(" %s", lieu[i]);
		int beg = 1LL*K*(V-1) % N;
		printf("Case #%d:", t);
		if(beg+K > N)
		{
			int end = beg+K-N;
			for(int i = 0; i < end; ++i)
				printf(" %s", lieu[i]);
		}
		for(int i = 0; (i < K) && (beg+i < N); ++i)
			printf(" %s", lieu[beg+i]);
		putchar('\n');
	}
	return 0;
}

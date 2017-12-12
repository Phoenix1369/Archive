#include <algorithm>
#include <cstdio>
const int MAXC = 105;
char buff[MAXC]{ };
int M, N, T;

int main()
{
	scanf("%d", &T);
	for(int _ = 0; _ < T; ++_)
	{
		int cost[2]{ };
		scanf(" %d%d", &N, &M);
		for(int i = 0; i < N; ++i)
		{
			scanf(" %s", buff);
			for(int j = 0; j < M; ++j)
				if(buff[j] == 'R')
					cost[(i & 1) ^ (j & 1)] += 5; // red->green
				else
					cost[(i & 1)== (j & 1)] += 3; // green->red
		}
		printf("%d\n", std::min(cost[0], cost[1]));
	}
	return 0;
}
#include <algorithm>
#include <cstdio>
#include <queue>
#define CODE "pie_progress"
typedef std::priority_queue<int> prq;
const int MAXM = 305;
int pie[MAXM]{ };
int M, N, T;

int main()
{
	freopen(CODE ".txt", "r", stdin);
	freopen(CODE ".out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		prq heap;
		scanf(" %d%d", &N, &M);
		int ret = 0;
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < M; ++j)
				scanf("%d", &pie[j]);
			std::sort(pie, pie+M);
			for(int j = 0; j < M; ++j)
			{
				int cost = pie[j] + j*2 + 1;
				heap.push(-cost);
			}
			ret += heap.top();
			heap.pop();
		}
		printf("Case #%d: %d\n", t, -ret);
	}
	return 0;
}

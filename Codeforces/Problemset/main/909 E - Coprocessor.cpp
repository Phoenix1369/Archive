#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 1E5+5;
int	E[MAXN]{ };
int final[MAXN][2]{ };
vin graph[MAXN]{ };
int indeg[MAXN]{ };
int	Q[MAXN]{ };
int M, N, qtr[2], res[2]{ };

int main()
{
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; ++i)
		scanf("%d", &E[i]);
	for(int i = 0; i < M; ++i)
	{
		int u, v;
		scanf("%d%d", &v, &u);
		graph[u].push_back(v);
		++indeg[v];
	}
	qtr[0] = qtr[1] = 0;
	for(int i = 0; i < N; ++i) if(!indeg[i])
	{
		final[i][1] = final[i][E[i]^1] = 1;
		Q[qtr[1]++] = i;
	}
	while(qtr[0] < qtr[1])
	{
		int cur = Q[qtr[0]++];
		for(auto nxt: graph[cur])
		{
			bool B = (E[nxt] && !E[cur]);
			for(int k = 0; k < 2; ++k)
				final[nxt][k] = std::max(final[cur][k]+B, final[nxt][k]);
			if(!--indeg[nxt])
				Q[qtr[1]++] = nxt;
		}
	}
	for(int i = 0; i < N; ++i) if(graph[i].empty())
	for(int j = 0; j < 2; ++j)
		res[j] = std::max(final[i][j], res[j]);
	printf("%d\n", std::min(res[0], res[1]));
	return 0;
}
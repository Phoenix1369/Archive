#include <cstdio>
typedef long long lld;
const int MAXN = 305;
lld graph[MAXN][MAXN]{ };
bool skip[MAXN][MAXN]{ };
lld M, ret=0;
int N;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	for(int j = 1; j <= N; ++j)
		scanf("%d", &graph[i][j]);
	for(int k = 1; k <= N; ++k)
	for(int i = 1; i <= N; ++i) if(k != i)
	for(int j = 1; j <= N; ++j) if(k != j && i != j)
		if(graph[i][k] + graph[k][j] < graph[i][j])	// Contradiction
			return puts("-1"), 0;
		else if(graph[i][k] + graph[k][j] == graph[i][j])
			skip[i][j] = skip[j][i] = true;		// Use other Edges
	for(int i = 1; i < N; ++i)
	for(int j = i+1; j <= N; ++j)
		if(!skip[i][j]) ret += graph[i][j];
	printf("%lld\n", ret);
	return 0;
}
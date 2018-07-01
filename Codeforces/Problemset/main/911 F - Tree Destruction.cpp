#include <cstdio>
#include <cstring>
#include <vector>
#define MMS(x, y) memset((x), (y), sizeof(x))
typedef long long lld;
typedef std::vector<int> vin;
const int MAXN = 2E5+5;
int   dis[MAXN]{ };
int  dis2[MAXN]{ };
vin graph[MAXN]{ };
bool seen[MAXN]{ };
int N, R=1, R2;
vin out, out2;
lld sum=0LL;

void dfs(int cur)
{
	for(auto nxt: graph[cur]) if(dis[nxt] == -1)
	{
		dis[nxt] = dis[cur] + 1;
		dfs(nxt);
	}
	if(dis[R] < dis[cur]) R=cur;
}

void dfs2(int cur)
{
	for(auto nxt: graph[cur]) if(dis2[nxt] == -1)
	{
		dis2[nxt] = dis2[cur] + 1;
		dfs2(nxt);
		seen[cur] |= seen[nxt];
	}
	if(seen[cur] || (dis2[cur] > dis[cur]))
	{
		out2.push_back(cur);
		sum += dis2[cur];
	}
	else if(cur != R)
	{
		out.push_back(cur);
		sum += dis[cur];
	}
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i < N; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	MMS(dis, -1); dis[R]=0; dfs(R);
	MMS(dis, -1); dis[R]=0; dfs(R2=R);
	seen[R2] = true;
	MMS(dis2, -1); dis2[R]=0; dfs2(R);
	printf("%lld\n", sum);
	for(auto itr: out) if(itr != R2)
		printf("%d %d %d\n", R2, itr, itr);
	for(auto itr: out2) if(itr != R)
		printf("%d %d %d\n",  R, itr, itr);
	return 0;
}
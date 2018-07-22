#include <cstdio>
#include <vector>
#define CODE "ethan_traverses_a_tree"
const int MAXN = 2018;
typedef std::vector<int> vin;
int A[MAXN], B[MAXN];
int color[MAXN]{ };
vin graph[MAXN]{ };
vin pre, post;
int K, N, T;

void dfs(int cur, int C)
{
	color[cur] = C;
	for(int nxt: graph[cur])
		if(!color[nxt])
			dfs(nxt, C);
}

void dfs_pre(int cur)
{
	pre.push_back(cur);
	if(A[cur]) dfs_pre(A[cur]);
	if(B[cur]) dfs_pre(B[cur]);
}
void dfs_post(int cur)
{
	if(A[cur]) dfs_post(A[cur]);
	if(B[cur]) dfs_post(B[cur]);
	post.push_back(cur);
}

int main()
{
	// freopen(CODE "_sample_input.txt", "r", stdin);
	// freopen(CODE ".example.out", "w", stdout);
	freopen(CODE ".txt", "r", stdin);
	freopen(CODE ".out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		scanf(" %d%d", &N, &K);
		for(int i = 1; i <= N; ++i)
			scanf(" %d%d", &A[i], &B[i]);
		dfs_pre(1);
		dfs_post(1);
		for(int i = 0; i < N; ++i)
			if(pre[i] != post[i])
			{
				graph[pre[i]].push_back(post[i]);
				graph[post[i]].push_back(pre[i]);
			}
		int ktr=0;
		for(int i = 1; i <= N; ++i) if(!color[i])
			dfs(i, ++ktr);
		// Output
		if(ktr >= K)
		{
			printf("Case #%d:", t);
			for(int i = 1; i <= N; ++i)
				printf(" %d", std::min(color[i], K));
			putchar('\n');
		}
		else
			printf("Case #%d: Impossible\n", t);
		// Reset
		for(int i = 1; i <= N; ++i)
		{
			A[i] = B[i] = color[i] = 0;
			graph[i].clear();
		}
		pre.clear();
		post.clear();
	}
    return 0;
}

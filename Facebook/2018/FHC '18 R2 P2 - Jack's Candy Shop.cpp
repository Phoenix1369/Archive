#include <cstdio>
#include <set>
#include <vector>
#define CODE "jacks_candy_shop"
typedef long long lld;
typedef std::vector<int> vin;
const int MAXN = 2e5+5;
int A, B, M, N, T;
int P[MAXN];
std::set<int> can[MAXN];
int cus[MAXN];
vin G[MAXN];
lld ret;

void dfs(int cur)
{
	for(int nxt: G[cur])
		dfs(nxt);
	// Merge subtree
	for(int nxt: G[cur])
	{	// Merge: Small -> Large
		bool B = (can[cur].size() >= can[nxt].size());
		int mx = B ? cur : nxt;
		int mn = B ? nxt : cur;
		for(int itr: can[mn])
			can[mx].insert(itr);
		can[mn].clear();
		if(!B)
			can[nxt].swap(can[cur]);
	}
	int k = std::min((int)can[cur].size(), cus[cur]);
	for(int i = 0; i < k; ++i)
	{
		int c = *can[cur].rbegin();
		can[cur].erase(c);
		ret += c;
	}
}

int main()
{
	// freopen(CODE "_sample_input.txt", "r", stdin);
	freopen(CODE ".txt", "r", stdin);
	freopen(CODE ".out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		scanf(" %d%d%d%d", &N, &M, &A, &B);
		// Reset
		ret = 0LL;
		for(int i = 0; i < N; ++i)
		{
			can[i].clear();
			can[i].insert(i);
			cus[i] = 0;
			G[i].clear();
		}
		// Customer subtree root
		for(int i = 0; i < M; ++i)
			++cus[(1LL*A*i + B) % N];
		for(int i = 1; i < N; ++i)
		{
			scanf("%d", &P[i]);
			G[P[i]].push_back(i);
		}
		dfs(0);
		printf("Case #%d: %lld\n", t, ret);
	}
	return 0;
}

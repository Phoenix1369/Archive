#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 1e6+5;
char c[MAXN];
vin g[MAXN];
bool m[MAXN], v[MAXN];
char cmd[9];
int n, x;

void dfs(int cur)
{	// Compute node values
	for(int nxt: g[cur])
		dfs(nxt);
	switch(c[cur])
	{
	case 'A': v[cur] = v[g[cur][0]] && v[g[cur][1]]; break;
	case 'N': v[cur] = !v[g[cur][0]]; break;
	case 'O': v[cur] = v[g[cur][0]] || v[g[cur][1]]; break;
	case 'X': v[cur] = v[g[cur][0]] ^ v[g[cur][1]]; break;
	}
}

void dfs2(int cur)
{	// Determine whether change matters
	for(int i = 0; i < (int)g[cur].size(); ++i)
	{
		switch(c[cur])
		{
		case 'A': m[g[cur][i]] = m[cur] && v[g[cur][i^1]]; break;
		case 'N': m[g[cur][i]] = m[cur]; break;
		case 'O': m[g[cur][i]] = m[cur] && !v[g[cur][i^1]]; break;
		case 'X': m[g[cur][i]] = m[cur]; break;
		}
		dfs2(g[cur][i]);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf(" %s%d", cmd, &x);
		switch(c[i]=cmd[0])
		{
		case 'A': case 'O': case 'X':
			g[i].push_back(x);
			scanf("%d", &x);
		case 'N':	// Fallthrough!
			g[i].push_back(x);
			break;
		case 'I': v[i] = x; break;
		}
	}
	dfs(1);
	m[1] = true;
	dfs2(1);
	for(int i = 2; i <= n; ++i) if(c[i] == 'I')
		putchar('0'+(v[1]^m[i]));
	putchar('\n');
	return 0;
}

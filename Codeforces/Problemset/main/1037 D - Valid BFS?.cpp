#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 2e5+5;
int a[MAXN], d[MAXN]{ }, q[MAXN];
vin g[MAXN]{ };
int n;

bool bfs()
{
    int qh, qt, src=1;
    qh = qt = 0;
    d[src] = 1;
    q[qt++] = src;
    while(qh < qt)
    {
        int cur = q[qh++];
        for(int nxt: g[cur]) if(!d[nxt])
        {
            d[nxt] = d[cur]+1;
            q[qt++] = nxt;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        q[i] = d[a[i]];
    }
    a[0] = q[0] = 0;
    for(int i = 1; i <= n; ++i)
        d[i] = 0;
    d[1] = 1;
    int cnt=1;
    for(int i = 1; i <= n; ++i)
        if(q[i-1] < q[i])
        {
            cnt = 1;
            for(int nxt: g[a[i]]) if(!d[nxt])
                d[nxt] = cnt;
        }
        else if(q[i-1] == q[i])
        {
            if(d[a[i-1]] > d[a[i]])
                return false;
            ++cnt;
            for(int nxt: g[a[i]]) if(!d[nxt])
                d[nxt] = cnt;
        }
        else
            return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; ++i)
    {
        int u, v;
        scanf(" %d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    puts(bfs() ? "Yes" : "No");
    return 0;
}


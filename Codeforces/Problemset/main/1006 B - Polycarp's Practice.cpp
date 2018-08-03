#include <cstdio>
#include <map>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 2018;
bool res[MAXN]{ };
std::map<int,vin> pos;
int a, k, n, ret=0;

int main()
{
	scanf(" %d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);
		pos[a].push_back(i);
	}
	for(int i = 1; i <= k; ++i)
	{
		int key = pos.rbegin()->first;
		vin& lst = pos.rbegin()->second;
		res[lst.back()] = true;
		lst.pop_back();
		if(lst.empty())
			pos.erase(key);
		ret += key;
	}
	printf("%d\n", ret);
	int cnt, last, prv;
	cnt = last = prv = 0;
	for(int i = 1; i <= n; ++i)
	{
		++cnt;
		if(res[i])
		{
			if(last)
				printf("%d ", prv);
			last = i;
			prv = cnt;
			cnt = 0;
		}
	}
	printf("%d\n", prv+cnt);
    return 0;
}

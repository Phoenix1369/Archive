#include <cstdio>
#include <set>
#define x first
const int MAXN = 4e5+5;
const int MOD = 1e9+7;
char s[MAXN];
std::set<int> beg, end, two;
int n, p, ret=1;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf(" %s%d", s, &p);
		switch(s[1])
		{
		case 'C': // ACCEPT
			if(two.count(p))
			{
				for(auto itr = two.begin(); itr != two.end();)
				{
					if(*itr < p)
						beg.insert(*itr);
					else if(p < *itr)
						end.insert(*itr);
					itr = two.erase(itr);
				}
				ret = 2LL*ret % MOD;
			}
			else if(beg.count(p))
			{
				if(p == *beg.rbegin())
				{
					beg.erase(p);
					for(int off: two)
						end.insert(off);
					two.clear();
				}
				else
					ret = 0;
			}
			else // end.count(p)
			{
				if(p == *end.begin())
				{
					end.erase(p);
					for(int off: two)
						beg.insert(off);
					two.clear();
				}
				else
					ret = 0;
			}
			break;
		case 'D': // ADD
			if(beg.empty() && end.empty())
				two.insert(p);
			else if(beg.empty())
			{
				if(p < *end.begin())
					two.insert(p);
				else
					end.insert(p);
			}
			else if(end.empty())
			{
				if(p > *beg.rbegin())
					two.insert(p);
				else
					beg.insert(p);
			}
			else
			{
				if(p <= *beg.rbegin())
					beg.insert(p);
				else if(p >= *end.begin())
					end.insert(p);
				else
					two.insert(p);
			}
			break;
		}
		if(!ret) break;
	}
	ret = 1LL*ret*(two.size()+1LL) % MOD;
	printf("%d\n", ret);
	return 0;
}

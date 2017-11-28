#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef std::vector<int> vin;
const int MAXC = 1E5+5;
const int MAXL = 26;
char buff[MAXC]{ };
vin   pos[MAXL]{ };
int L;

bool f(int k)
{
	for(int c = 0; c < MAXL; ++c) if(!pos[c].empty())
	{
		bool kdom = true;
		for(int i = L-k; i >= 0; --i)
		{
			auto ptr = std::lower_bound(ALL(pos[c]), i);
			kdom &= (ptr != pos[c].end()) && (*ptr < i+k);
		}
		if(kdom) return true;
	}
	return false;
}

int main()
{
	scanf(" %s", buff);
	L = strlen(buff);
	for(int i = 0; i < L; ++i)
		pos[buff[i]-'a'].push_back(i);
	int lo=1, hi=L;
	while(lo < hi)
	{
		int ce = (lo+hi)/2;
		if(f(ce))
			hi = ce;
		else
			lo = ce+1;
	}
	printf("%d\n", lo);
	return 0;
}

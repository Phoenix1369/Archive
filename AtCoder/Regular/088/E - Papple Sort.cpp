#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <set>
typedef long long lld;
const int MAXA = 26;
const int MAXC = 2E5+5;
char buff[MAXC]{ };
int  dest[MAXC]{ };
std::deque<int> pos[MAXA]{ };
lld ret=0LL;
int L;

struct BinaryIndexedTree
{
	int data[MAXC]{ };

	void add(int x)
	{
		for(int i = x; i <= L; i += i & -i)
			++data[i];
	}

	int get(int x)
	{
		int sum = 0;
		for(int i = x; i >= 1; i -= i & -i)
			sum += data[i];
		return	sum;
	}
} bintr;

int main()
{
	scanf("%s", buff+1);
	L = strlen(buff+1);
	for(int i = 1; i <= L; ++i)
		pos[buff[i]-'a'].push_back(i);
	int odd = -1;
	for(int i = 0; i < MAXA; ++i)
		if(pos[i].size() & 1)
		{
			if(odd != -1)
				return puts("-1"), 0;
			odd = i;
		}
	if(odd != -1)
	{	// Handle Unique Centre
		int mid = pos[odd][pos[odd].size() / 2];
		for(int i = 0; i < MAXA; ++i)
			for(int j = 0; j*2 < (int)pos[i].size(); ++j)
				ret +=	(pos[i][j] > mid) +
					(pos[i][(int)pos[i].size()-j-1] < mid);
	}
	int cnt = 1;
	for(int i = 1; i <= L; ++i) if(!dest[i])
	{	// Record Destinations
		int beg = pos[buff[i]-'a'].front();
		int end = pos[buff[i]-'a'].back();
		pos[buff[i]-'a'].pop_front();
		if(beg == end) continue;
		pos[buff[i]-'a'].pop_back();
		dest[end] = L-cnt+1;
		dest[beg] = cnt++;
	}
	for(int i = 1; i <= L; ++i) if(dest[i])
	{	// Compute Inversions
		ret += bintr.get(L-dest[i]+1);
		bintr.add(L-dest[i]+1);
	}
	printf("%lld\n", ret);
	return 0;
}
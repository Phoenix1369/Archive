#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef std::vector<int> vin;
const int MAXN = 100;
const int MAXX = 1E4;
int     H[MAXN]{ };
std::map<int,int> count;
vin beg[MAXX], end[MAXX];
int N, ret=0;
vin event;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		int l, r;
		scanf(" %d%d%d", &H[i], &l, &r);
		beg[l].push_back(i);
		end[r].push_back(i);
		event.push_back(l);
		event.push_back(r);
	}
	std::sort(ALL(event));
	event.erase(std::unique(ALL(event)), event.end());
	for(auto p: event)
	{	// Does Not Overlap with `beg`
		std::sort(ALL(end[p]), [&](int l, int r) { return H[l] > H[r]; });
		for(auto y: end[p])
		{
			auto mtr = count.lower_bound(H[y]);
			ret += H[y] - ((mtr != count.begin()) ? (--mtr)->first : 0);
			if(!--count[H[y]])
				count.erase(H[y]);
		}
		std::sort(ALL(beg[p]), [&](int l, int r) { return H[l] < H[r]; });
		for(auto y: beg[p])
		{
			auto mtr = count.lower_bound(H[y]);
			ret += H[y] - ((mtr != count.begin()) ? (--mtr)->first : 0);
			++count[H[y]];
		}
	}
	printf("%d\n", ret);
	return 0;
}

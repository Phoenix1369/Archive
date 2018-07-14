#include <algorithm>
#include <cstdio>
#include <utility>
#define x first
#define y second
typedef long long lld;
typedef std::pair<int,int> pii;
const int MAXN = 5E5+5;
pii cell[MAXN]{ };
int row[MAXN]{ };
int N, X, Y;
lld cnt=0LL;

struct BinaryIndexedTree
{
	lld data[MAXN]{ };

	void add(int x, int v)
	{
		for(int i = x; i <= N; i += i & -i)
			data[i] += v;
	}

	lld sum(int x)
	{
		lld ret = 0;
		for(int i = x; i >= 1; i -= i & -i)
			ret += data[i];
		return ret;
	}
} bintr;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &cell[i].x);
	X = Y = 1E9+5;
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &cell[i].y);
		X = std::min(cell[i].x, X);
		Y = std::min(cell[i].y, Y);
	}
	for(int i = 0; i < N; ++i)
	{
		cell[i].x -= X;
		cell[i].y -= Y;
		++cell[i].y;
		row[cell[i].y] = -1;
	}
	std::sort(cell, cell+N);
	for(int i = 0; i < N; ++i)
	{
		// Col operation:
		//   include column
		//   flag rows to exclude cur col
		// Row operation:
		//   include row
		//   exclude cols intersecting with cur row
		// Reset excluded col count of cur row
		if(i && (cell[i-1].x == cell[i].x))
		{
			cnt += cell[i].y - cell[i-1].y - 1;
			bintr.add(cell[i-1].y+1, +1);
			bintr.add(cell[i].y, -1);
		}
		lld columns = bintr.sum(cell[i].y);
		if(row[cell[i].y] != -1)
		{
			cnt += cell[i].x - row[cell[i].y] - 1;
			cnt -= columns;
		}
		bintr.add(cell[i].y,  -columns);
		bintr.add(cell[i].y+1, columns);
		row[cell[i].y] = cell[i].x;
	}
	printf("%lld\n", cnt);
	return 0;
}

#include <algorithm>
#include <cstdio>
const int INFN = 1e9+7;
const int MAXN = 2e5+5;
int n;

struct Rect
{
	int xa, xb, ya, yb;

	Rect& operator &= (const Rect& rhs)
	{
		xa = std::max(rhs.xa, xa);
		xb = std::min(rhs.xb, xb);
		ya = std::max(rhs.ya, ya);
		yb = std::min(rhs.yb, yb);
		return *this;
	}

	Rect operator & (Rect rhs) const
	{
		Rect cpy = *this;
		return cpy &= rhs;
	}

	bool operator ! () const { return (xa > xb) || (ya > yb); }
} a[MAXN], b[MAXN];

int main()
{
	scanf("%d", &n);
	a[0] = b[n+1] = { -INFN, INFN, -INFN, INFN };
	for(int i = 1; i <= n; ++i)
	{
		scanf(" %d%d%d%d", &a[i].xa, &a[i].ya, &a[i].xb, &a[i].yb);
		b[i] = a[i];
		a[i] &= a[i-1];
	}
	for(int i = n; i >= 1; --i)
	{
		b[i] &= b[i+1];
		Rect c = (a[i-1] & b[i+1]);
		if(!c) continue;
		printf("%d %d\n", c.xa, c.ya);
		break;
	}
	return 0;
}

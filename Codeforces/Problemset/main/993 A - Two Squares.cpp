#include <cmath>
#include <cstdio>
#include <utility>
#define x first
#define y second
typedef std::pair<int,int> pii;
pii c[2]{ }, p[2][4];

int main()
{
	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			scanf(" %d%d", &p[i][j].x, &p[i][j].y);
			c[i].x += p[i][j].x *= 2;
			c[i].y += p[i][j].y *= 2;
		}
		c[i].x /= 4;
		c[i].y /= 4;
	}
	int edge = std::abs(p[0][0].x - c[0].x);
	int tilt = std::abs(p[1][0].x + p[1][1].x - 2*c[1].x);
	int dx = std::abs(c[0].x-c[1].x);
	int dy = std::abs(c[0].y-c[1].y);

	bool out = (dx+dy <= 2*edge+tilt);
	bool inn = (dx <= edge+tilt) && (dy <= edge+tilt);
	puts((out && inn) ? "YES" : "NO");
	return 0;
}

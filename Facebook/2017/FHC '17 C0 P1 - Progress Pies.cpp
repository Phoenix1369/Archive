#include <cmath>
#include <cstdio>
#define CODE "progress_pie"
const double PI = 3.1415926535897932384626;
const int R2=50*50; // Radius^2
int P, T, X, Y;

int main()
{
	freopen(CODE ".txt", "r", stdin);
	freopen(CODE ".out", "w", stdout);
	scanf("%d", &T);
	for(int _  = 1; _ <= T; ++_)
	{
		scanf(" %d%d%d", &P, &X, &Y);
		if(!P)
		{	// All White Pixels
			printf("Case #%d: white\n", _);
			continue;
		}
		int dx=X-50, dy=Y-50;
		if(!dx && !dy)
		{	// Centre Pixel [Domain Error]
			printf("Case #%d: black\n", _);
			continue;
		}
		if(dx*dx+dy*dy > R2)
		{	// Outside of Circle
			printf("Case #%d: white\n", _);
			continue;
		}
		double deg = P * 3.6; // Progress
		double pos = atan2(dy, dx) * 180.0 / PI;
		if(pos <   0) pos += 360;
		if(pos <= 90)
			pos = 90 - pos;
		else
			pos = 450- pos;
		if(pos >= 360) pos -= 360; // 'pos' within 'deg'
		printf("Case #%d: %s\n", _, (pos <= deg) ? "black" : "white");
	}
	return 0;
}
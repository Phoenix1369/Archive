#include <cmath>
#include <cstdio>
#define CODE "progress_pie"
const double PI = acos(-1);
const int R = 50; // Radius
int P, T, X, Y;

bool solve()
{	// No progress
	if(!P) return false;
	int dx=X-50, dy=Y-50;
	// Centre pixel [domain error]
	if(!dx && !dy)
		return true;
	// Outside of circle
	if(hypot(dx, dy) > R)
		return false;
	double deg = P * 3.6; // Progress
	double pos = atan2(dy, dx) * 180.0 / PI;
	if(pos < 0) pos += 360;
	if(pos <= 90)
		pos = 90 - pos;
	else
		pos = 450 - pos;
	if(pos >= 360) pos -= 360;
	return (pos <= deg);
}

int main()
{
	freopen(CODE ".txt", "r", stdin);
	freopen(CODE ".out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		scanf(" %d%d%d", &P, &X, &Y);
		printf("Case #%d: %s\n", t, solve() ? "black" : "white");
	}
	return 0;
}

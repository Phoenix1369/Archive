#include <algorithm>
#include <cstdio>
#define CODE "fighting_the_zombie"
const double EPS = 1E-11;
const int MAXD = 425;
double dp[MAXD]{ };
int H, S, T;
double A, B;
char C;

int main()
{
	freopen(CODE ".txt", "r", stdin);
	freopen(CODE ".out", "w", stdout);
	scanf("%d", &T);
	for(int _ = 1; _ <= T; ++_)
	{
		A = 0.0;
		scanf(" %d%d", &H, &S);
		for(int i = 0; i < S; ++i)
		{	// Read Dice Input!
			B = 0.0;
			int add, die, mul;
			scanf(" %dd%d", &mul, &die);
			C = getchar();
			if(C=='+' || C=='-')
			{
				scanf("%d", &add);
				if(C=='-') add = -add;
			}
			else
				add = 0;
			int lim = mul*die;
			double rec = 1.0 / die; // Reciprocal
			for(int k = lim; k >  0; --k)
				dp[k] = 0.0;
			dp[0] = 1.0;
			for(int j = 0; j < mul; ++j)
			{	// Times Rolled
				for(int k = lim; k >= 0; --k) if(dp[k] > EPS) // Damage Dealt
				{
					for(int l = 1; l <= die; ++l) // New Dice
						dp[k+l] += dp[k] * rec;
					dp[k] = 0.0; // Reset for Next Layer
				}
			}
			for(int k = 1; k <= lim; ++k)
				if(k+add >= H) // Kills Zombie
					B += dp[k];
			A = std::max(B, A);
		}
		A = std::min(1.0, A);
		printf("Case #%d: %.9f\n", _, A);
	}	// Time Complexity: O(T * S * X^2 * Y^2)
	return 0;
}
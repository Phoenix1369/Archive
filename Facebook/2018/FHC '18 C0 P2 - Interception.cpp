#include <cstdio>
#define CODE "interception"
int N, T;

int main()
{
	// freopen(CODE "_example_input.txt", "r", stdin);
	// freopen(CODE "_example_output.txt", "w", stdout);
	freopen(CODE ".txt", "r", stdin);
	freopen(CODE ".out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		scanf("%d", &N);
		for(int i = 0; i <= N; ++i)
			scanf("%*d");
		printf("Case #%d: ", t);
		puts((N & 1) ? "1\n0.0" : "0");
	}
	return 0;
}

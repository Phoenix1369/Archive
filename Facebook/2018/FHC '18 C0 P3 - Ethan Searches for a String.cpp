#include <cstdio>
#include <cstring>
#define CODE "ethan_searches_for_a_string"
const int MAXC = 2018;
char buff[MAXC]{ };
int N, T;

bool ethan()
{
	int L = strlen(buff);
	for(int i = 1; i < L; ++i)		// ABACUS   | Prefix
	for(int j = 0; i+j < L; ++j)	//   ABACUS | String
		if(buff[i+j] != buff[j])
		{
			if(j)
			{
				for(int k = 0; k < i; ++k)
					putchar(buff[k]);
				return true;
			}
			break;
		}
	return false;
}

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
		scanf(" %s", buff);
		printf("Case #%d: ", t);
		puts(ethan() ? buff : "Impossible");
	}
	return 0;
}

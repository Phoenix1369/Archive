#include <cstdio>
const int MAXY = 12;
const int DAYS[MAXY] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAXN = MAXY<<1;
int	A[MAXN]{ };
int N, xxix=0;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
		if(A[i] == 29)
			--A[i], ++xxix;
	}
	if(xxix > 1) return puts("NO"), 0;
	for(int i = 0; i < MAXY; ++i)
	{
		bool yes = true;
		for(int j = 0; j < N; ++j)
			if(A[j] != DAYS[(i+j) % MAXY])
				yes=false, j=N;
		if(yes) return puts("YES"), 0;
	}
	puts("NO");
	return 0;
}
#include <cstdio>
#define ALL(x) (x).begin(), (x).end()
const char * IMPL = "->";
const int MAXN = 1E5+5;
int	A[MAXN]{ };
bool open[MAXN]{ };
bool shut[MAXN]{ };
int N;

/* procedure implication()
 * observe that (0->1) = (1->1) = 1
 * case #1: A = `.. -> 1` is not valid
 * case #2: A = `0` or `.. -> 1 -> 0` is valid
 * case #3: A = `.. -> (0 -> (ALL_ONES -> 0)) -> 0` is valid
 * default: A is not valid
 */
bool implication()
{	// Resolves Implication Statements
	if(A[N])
		return false;
	if((N == 1) || A[N-1])
		return true;
	for(int i = N-2; i >= 1; --i) if(!A[i])
		return open[i] = open[i+1] = shut[N-1] = true;
	return false;
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
	if(implication())
	{
		puts("YES");
		for(int i = 1; i <= N; ++i)
		{
			if(open[i]) putchar('(');
			putchar(A[i]+'0');
			if(shut[i]) printf("))");
			if(i != N) printf(IMPL);
		}
	}
	else
		puts("NO");
	return 0;
}

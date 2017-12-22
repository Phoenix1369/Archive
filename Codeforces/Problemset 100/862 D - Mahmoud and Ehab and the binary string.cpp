#include <cstdio>
const int MAXC = 1005;
char buff[MAXC]{ };
int cur, N, one;

void ask()		{ printf("? %s\n",  buff+1); fflush(stdout); }
void out(int z, int a)	{ printf("! %d %d\n", z, a); fflush(stdout); }

void descend(int L, int R, int prv, int sum)
{
	int M = (L+R)>>1;
	for(int i = M+1; i <= R; ++i)
		buff[i] ^= 1;
	ask();	scanf("%d", &cur);
	int car = (cur + prv - sum*2 - (R-M))/2; // buff[M+1] in [L,M]
	int cdr = (cur - car - sum);		 // buff[M] in [M+1,R]
	bool B = (buff[M] == '1');
	if(!car && !cdr)
		out(M+B, M+(B^1));	// Split
	else if((car == M-L+1) && (cdr == R-M))
		out(M+(B^1), M+B);	// Split
	else if(cdr && (cdr != R-M))
		descend(M+1, R, cur, sum+car);
	else
		descend(L  , M, cur, sum+cdr);
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		buff[i] = '0';
	ask();	scanf("%d", &one);
	descend(1, N, one, 0);
	return 0;
}
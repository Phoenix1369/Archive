#include <cstdio>
const int MAXQ = 1E5+5;
int  psum[MAXQ]{ };
int	S[MAXQ]{ };
int l, Q, r;

void init()
{
	S[0] = S[1] = 1;
	for(int i = 2; i < MAXQ; ++i) if(!S[i])
		for(int j = i; j < MAXQ; j += i)
			S[j] = i;
	for(int i = 3; i < MAXQ-1; ++i)
		psum[i] = psum[i-1] + ((S[i] == i) && (S[i+1] == (i+1)>>1));
}

int main()
{
	init();
	scanf("%d", &Q);
	for(int _ = 0; _ < Q; ++_)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", psum[r]-psum[l-1]);
	}
	return 0;
}
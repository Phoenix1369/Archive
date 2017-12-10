#include <cstdio>
const int MAXC = 105;
char buff[MAXC]{ };
int   out[MAXC]{ };
int K, L, N;

int main()
{
	scanf(" %d%s", &N, buff); K=L=0;
	for(char * ptr = buff; *ptr; ++ptr)
		if(*ptr == 'B')
			++out[K];
		else if(out[K])
			++K;
	if(out[K]) ++K;
	printf("%d\n", K);
	for(int i = 0; i < K; ++i)
		printf("%d ", out[i]);
	return 0;
}
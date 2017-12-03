#include <cstdio>
const int MAXC = 105;
char buff[MAXC]{ };
int M, N;

int main()
{
	scanf(" %d%d%s", &N, &M, buff+1);
	for(int i = 0; i < M; ++i)
	{
		int l, r;
		char c1, c2;
		scanf(" %d%d %c %c", &l, &r, &c1, &c2);
		for(int j = l; j <= r; ++j)
			if(buff[j] == c1)
				buff[j] = c2;
	}
	puts(buff+1);
	return 0;
}

#include <cstdio>
const int MAXC = 105;
char buff[MAXC]{ };
int cnt=1, D, N, pos=1;

int main()
{
	scanf(" %d%d%s", &N, &D, buff+1);
	for(int j = D; (pos+D < N) && (j >= 1); --j)
		if(buff[pos+j]-'0')
		{
			pos += j;
			j = D+1;
			++cnt;
		}
	if(pos+D >= N)
		printf("%d\n", cnt);
	else
		puts("-1");
	return 0;
}
#include <cstdio>
#include <cstring>
const int MAXN = 125;
char s[MAXN];
int cb, rb=-1, re;
int d, n;

int main()
{
	scanf(" %d%*d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		char * p = strchr(s, 'B');
		if(p == nullptr)
			continue;
		cb = p-s;
		if(rb == -1)
			rb = i;
		re = i;
	}
	int d = (re-rb)/2;
	printf("%d %d\n", rb+d+1, cb+d+1);
	return 0;
}

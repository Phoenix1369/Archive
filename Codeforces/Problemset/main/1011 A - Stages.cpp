#include <cstdio>
#include <cstring>
const int MAXA = 26;
const int MAXC = 55;
bool yes[MAXA]{ };
char s[MAXC];
int k, n;

int main()
{
	scanf(" %d%d", &n, &k);
	scanf(" %s", s);
	int L = strlen(s);
	for(int i = 0; i < L; ++i)
		yes[s[i]-'a'] = true;
	int prv=-2, ret=0;
	for(int i = 0; k && (i < MAXA); ++i)
		if(yes[i] && (i-prv > 1))
		{
			ret += i+1;
			prv = i;
			--k;
		}
	if(!k)
		printf("%d\n", ret);
	else
		puts("-1");
	return 0;
}

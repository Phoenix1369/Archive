#include <cstdio>
#include <cstring>
const int MAXC = 2e5+5;
char s[2][MAXC];
int len[2];

int main()
{
	for(int i = 0; i < 2; ++i)
	{
		scanf(" %s", s[i]);
		len[i] = strlen(s[i]);
	}
	while(len[0] && len[1] && (s[0][len[0]-1] == s[1][len[1]-1]))
		--len[0], --len[1];
	printf("%d\n", len[0]+len[1]);
    return 0;
}
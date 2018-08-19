#include <algorithm>
#include <cstdio>
#include <cstring>
const int MAXS = 1e5+5;
int pre[MAXS]{ };
int suf[MAXS]{ };
char s[MAXS];
int n;

int main()
{	// Swap segments: a..b|c..d -> b..a|d..c ~ c..d|a..b
	scanf(" %s", s+1);
	n = strlen(s+1);
	s[0] = s[1];
	for(int i = 1; i <= n; ++i)
		pre[i] = (s[i] != s[i-1]) ? (pre[i-1] + 1) : 1;
	s[n+1] = s[n];
	s[n+2] = '\0';
	for(int i = n; i >= 1; --i)
		suf[i] = (s[i] != s[i+1]) ? (suf[i+1] + 1) : 1;
	int ret = 0;
	for(int i = 1; i <= n; ++i)
		ret = std::max(std::max(pre[i], suf[i]), ret);
	if((pre[n] != n) && (s[1] != s[n]))
		ret = std::max(pre[n]+suf[1], ret);
	printf("%d\n", ret);
	return 0;
}

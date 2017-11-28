#include <algorithm>
#include <cstdio>
const int MAXC = 105;
char buff[MAXC]{ };
int cnt[26]{ };
int L;

int main()
{
	scanf("%d", &L);
	scanf(" %s", buff);
	for(int i = 0; i < L; ++i)
		++cnt[buff[i]-'A'];
	printf("%d\n",
		std::min(cnt['L'-'A'], cnt['R'-'A'])*2 +
		std::min(cnt['D'-'A'], cnt['U'-'A'])*2);
	return 0;
}

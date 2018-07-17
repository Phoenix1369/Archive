#include <algorithm>
#include <cstdio>
const int MAXN = 105;
char buff[MAXN]{ };
int n;

int main()
{
	scanf("%d", &n);
	scanf(" %s", buff);
	for(int d = 1; d <= n; ++d) if((n % d) == 0)
	for(int h = 0, t = d-1; h < t; ++h, --t)
		std::swap(buff[h], buff[t]);
	puts(buff);
    return 0;
}

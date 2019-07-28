#include <algorithm>
#include <cstdio>
#include <cstring>
const int MAXC = 1E5+5;
char buff[MAXC]{ };
int L, T;

int main()
{
	scanf("%s", buff);
	L = T = strlen(buff);
	for(int i = 1; i < L; ++i) if(buff[i-1] != buff[i])
		T = std::min(std::max(i, L-i), T);
	printf("%d\n", T);
	return 0;
}
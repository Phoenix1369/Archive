#include <algorithm>
#include <cstdio>
int S[3];

int main()
{
	for(int i = 0; i < 3; ++i)
		scanf("%d", &S[i]);
	std::sort(S, S+3);
	if(1LL*S[0]*S[1]*S[2] & 1)
		printf("%lld\n", 1LL*S[0]*S[1]);
	else
		puts("0");
	return 0;
}
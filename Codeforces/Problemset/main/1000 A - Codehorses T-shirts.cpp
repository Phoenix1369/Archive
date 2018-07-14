#include <algorithm>
#include <cstdio>
#include <cstring>
char buff[10];
int cnt[2][4][3]{ };
int L, N, ret=0;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < 2; ++i)
	for(int j = 0; j < N; ++j)
	{
		scanf(" %s", buff);
		L = strlen(buff); --L;
		if(buff[L] == 'S')
			++cnt[i][L][0];
		else if(buff[L] == 'M')
			++cnt[i][L][1];
		else
			++cnt[i][L][2];
	}
	for(int i = 0; i < 4; ++i)
	for(int j = 0; j < 3; ++j)
		ret += std::abs(cnt[0][i][j] - cnt[1][i][j]);
	printf("%d\n", ret / 2);
	return 0;
}

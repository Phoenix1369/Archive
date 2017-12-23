#include <algorithm>
#include <cstdio>
#include <cstring>
const int MAXD = 10;
int	A[MAXD]{ };
char buff[MAXD]{ };
bool lead[MAXD]{ };
int   sum[MAXD]{ };
int M, N, ret=0, skip=MAXD;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf(" %s", buff);
		for(int j = strlen(buff)-1, t=1; j >= 0; --j, t *= MAXD)
			sum[buff[j]-'a'] += t;
		lead[buff[0]-'a'] = true;
	}
	for(int i = 0; i < MAXD; ++i)
		if(!lead[i] && ((skip == MAXD) || (sum[skip] < sum[i])))
			skip = i; // Absorb Max Sum with `0`
	M = 0;
	for(int i = 0; i < MAXD; ++i)
		if(sum[i] && (i != skip))
			A[M++] = i;
	std::sort(A, A+M, [&](const int& l, const int& r) {
		return sum[l] > sum[r];
	});
	for(int i = 0; i < M; ++i)
		ret += (i+1)*sum[A[i]];
	printf("%d\n", ret);
	return 0;
}
#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 2E5+5;
int	A[MAXN]{ };
int cur=1, K, N;
vin S;

int main()
{
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; ++i)
	{
		if(i <= K)
			scanf("%d", &A[i]);
		else if(S.empty())
			A[i] = N;
		else
			A[i] = S.back()-1;
		S.push_back(A[i]);
		while(!S.empty() && (S.back() == cur))
			S.pop_back(), ++cur;
	}
	if(!S.empty())
		return puts("-1"), 0;
	for(int i = 1; i <= N; ++i)
		printf("%d%c", A[i], (i==N)?'\n':' ');
	return 0;
}
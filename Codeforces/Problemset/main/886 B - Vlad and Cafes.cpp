#include <cstdio>
#include <map>
std::map<int,int> V;
int caf, N;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &caf);
		V[caf] = i;
	}
	int ret = -1;
	for(auto itr: V)
		if((ret == -1) || (itr.second < V.at(ret)))
			ret = itr.first;
	printf("%d\n", ret);
	return 0;
}

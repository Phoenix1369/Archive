#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef std::vector<int> vin;
std::unordered_map<int,vin> add, sub;
int A, N, T, V;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf(" %d%d%d", &A, &T, &V);
		if(A == 1)
			add[V].insert(std::lower_bound(ALL(add[V]), T), T);
		else if(A == 2)
			sub[V].insert(std::lower_bound(ALL(sub[V]), T), T);
		else
			printf("%d\n",	(std::upper_bound(ALL(add[V]), T) - add[V].begin()) -
					(std::upper_bound(ALL(sub[V]), T) - sub[V].begin()) );
	}
	return 0;
}

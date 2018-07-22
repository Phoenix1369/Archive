#include <cstdio>
#include <unordered_set>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 1e5+5;
vin beg[MAXN], end[MAXN];
std::unordered_set<int> bad;
int a, b, M, N;

int main()
{
	scanf(" %d%d", &N, &M);
	bad.reserve(M);
	for(int i = 0; i < M; ++i)
	{
		scanf(" %d%d", &a, &b); --b;
		beg[a].push_back(i);
		end[b].push_back(i);
		bad.insert(i);
	}
	int ret = 0;
	for(int i = 1; i < N; ++i)
	{
		for(int edge: beg[i])
			bad.insert(edge);
		for(int edge: end[i])
			if(bad.count(edge))
			{
				bad.clear();
				++ret;
				break;
			}
	}
	printf("%d\n", ret);
	return 0;
}

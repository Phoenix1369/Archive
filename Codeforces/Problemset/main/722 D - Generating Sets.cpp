#include <cstdio>
#include <set>
std::set<int> Y;
int N, num;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &num);
		Y.insert(num);
	}
	while(true)
	{
		bool go = false;
		for(int k = *Y.rbegin(); k; k >>= 1) if(!Y.count(k))
		{	// Reduce Largest
			Y.erase(*Y.rbegin());
			Y.insert(k);
			go = true;
			break;
		}
		if(!go) break;
	}
	for(auto ytr: Y)
		printf("%d ", ytr);
	return 0;
}
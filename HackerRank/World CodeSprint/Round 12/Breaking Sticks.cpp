#include <algorithm>
#include <cstdio>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
const int MAXA = 1E6+5;
std::vector<int> P;
std::vector<lld> split;
bool S[MAXA]{ };
lld A, ret=0LL;
int N;

int main()
{
	S[0] = S[1] = true;
	for(int i = 2; i < MAXA; ++i) if(!S[i])
	{
		P.push_back(i);
		for(int j = i; j < MAXA; j += i)
			S[j] = true;
	}
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		split.reserve(50);
		scanf("%lld", &A);
		for(auto div: P)
			while((A % div) == 0)
			{
				split.push_back(div);
				A /= div;
			}
		if(A != 1) split.push_back(A);
		std::reverse(ALL(split));
		lld pcs=1LL;
		for(auto div: split)
		{
			pcs *= div;
			ret += pcs;
		}
		split.clear();
		++ret;
	}
	printf("%lld\n", ret);
	return 0;
}
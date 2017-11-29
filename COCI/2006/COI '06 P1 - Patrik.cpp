#include <cstdio>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
typedef std::vector<int> vin;
int cur, N;
vin stack;

int main()
{
	scanf("%d", &N);
	lld A = 0LL;
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &cur);
		cur *= -1; // Negate Heights
		while(!stack.empty() && (stack.back() > cur))
		{	// Pops off Magnitude Below
			stack.pop_back();
			++A;
		}
		if(!stack.empty() && (stack.back() == cur))
		{	// Equivalent Heights
			A += (stack.end() - std::lower_bound(ALL(stack), cur));
			if(stack.front() != cur) ++A;
		}
		else if(!stack.empty()) ++A;
		stack.push_back(cur);
	}
	printf("%lld\n", A);
	return 0;
}

#include <algorithm>
#include <cstdio>
const int MAXN = 1e5+5;
int h[MAXN], w[MAXN];
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf(" %d%d", &w[i], &h[i]);
	if(w[0] > h[0])
		std::swap(w[0], h[0]);
	for(int i = 1; i < n; ++i)
	{
		if(w[i] > h[i])
			std::swap(w[i], h[i]);
		if(w[i] > h[i-1])
			return puts("NO"), 0;
		if(h[i] > h[i-1])
			std::swap(w[i], h[i]);
	}
	puts("YES");
	return 0;
}

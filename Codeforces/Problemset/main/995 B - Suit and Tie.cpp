#include <algorithm>
#include <cstdio>
const int MAXN = 205;
int a[MAXN];
int n, nn;

int main()
{
	scanf("%d", &n); nn=2*n;
	for(int i = 1; i <= nn; ++i)
		scanf("%d", &a[i]);
	int ret = 0;
	for(int i = 1; i <= nn; i += 2) if(a[i] != a[i+1])
	{
		int j = i+2;
		while(a[j] != a[i]) ++j;
		while(a[j] != a[j-1])
		{
			std::swap(a[j], a[j-1]);
			++ret;
			--j;
		}
	}
	printf("%d\n", ret);
    return 0;
}

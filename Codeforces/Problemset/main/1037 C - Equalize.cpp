#include <cstdio>
const int MAXN = 1e6+5;
char a[MAXN], b[MAXN];
int n, ret=0;

int main()
{
    scanf(" %d%s%s", &n, a, b);
    for(int i = 1; i < n; ++i)
        if((a[i] != b[i]) && (a[i-1] != b[i-1]) && (a[i] != a[i-1]))
        {
            a[i] ^= 1;
            a[i-1] ^= 1;
            ++ret;
        }
    for(int i = 0; i < n; ++i)
        if(a[i] != b[i])
		{
			a[i] ^= 1;
			++ret;
		}
    printf("%d\n", ret);
    return 0;
}


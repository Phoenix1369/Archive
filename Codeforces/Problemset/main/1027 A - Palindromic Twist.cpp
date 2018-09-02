#include <cstdio>
#include <cstring>
#define MMS(x, y) memset((x), (y), sizeof(x))
const int MAXA = 26;
const int MAXN = 105;
bool yes[MAXN][MAXA];
char s[MAXN];
int n, T;

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		scanf(" %d%s", &n, s);
		int nh = n>>1;
		for(int i = 0; i < n; ++i)
			MMS(yes[i], false);
		bool ret = true;
		for(int i = 0; ret && (i < n); ++i)
		{
			if(s[i] > 'a') yes[i][s[i]-'a'-1] = true;
			if(s[i] < 'z') yes[i][s[i]-'a'+1] = true;
			if(i < nh) continue;
			bool good = false;
			for(int j = 0; j < MAXA; ++j)
				if(yes[i][j] && yes[n-i-1][j])
				{
					good = true;
					break;
				}
			ret &= good;
		}
		puts(ret ? "YES" : "NO");
	}
	return 0;
}

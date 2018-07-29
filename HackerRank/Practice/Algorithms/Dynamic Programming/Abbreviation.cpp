#include <cstdio>
#include <cstring>
const int MAXC = 1005;
const char sub='a'-'A';
char a[MAXC], b[MAXC];
int dp[MAXC][MAXC];
int Q;

int main()
{
	scanf("%d", &Q);
	for(int q = 0; q < Q; ++q)
	{
		scanf(" %s%s", a+1, b+1);
		int la=strlen(a+1), lb=strlen(b+1);
		for(int i = 0; i <= la; ++i)
		for(int j = 0; j <= lb; ++j)
			dp[i][j] = false;
		dp[0][0] = true;
		for(int i = 1; (i <= la) && (a[i] >= 'a'); ++i)
			dp[i][0] = true;
		for(int i = 1; i <= la; ++i)
		for(int j = 1; j <= lb; ++j)
			if(a[i] == b[j])
				dp[i][j] |= dp[i-1][j-1];
			else if(a[i] >= 'a')
			{
				if(b[j]+sub == a[i])
					dp[i][j] |= dp[i-1][j-1];
				dp[i][j] |= dp[i-1][j];
			}
		puts(dp[la][lb] ? "YES" : "NO");
	}
	return 0;
}

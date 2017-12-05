#include <cstdio>
#include <cstring>
#define MMS(x, y) memset((x), (y), sizeof(x))
const int MAXC = 5005;
const int MOD  = 1E9+7;
char buff[MAXC]{ };
int    dp[MAXC][MAXC]{ };
int K, L;

int dfs(int k, int l)
{	// Keystrokes Remaining, Length of Current String
	int& ret = dp[k][l];
	if(ret >= 0) return ret;
	// Keystrokes Maxed: Only Empty String = 1
	if(k == K) return !l;
	ret = 0;
	// Case: Backspace
	if(l == 0)	// Empty String
		ret = (1LL*dfs(k+1, l) + ret) % MOD; // Consume Keystroke
	if(l+1 < MAXC)
		ret = (2LL*dfs(k+1, l+1) + ret) % MOD; // Upperbound [x2: 0, 1]
	// Case: Digit Key
	if(l >= 1)
		ret = (1LL*dfs(k+1, l-1) + ret) % MOD;
	return ret;
}

int main()
{
	scanf("%d", &K);
	scanf(" %s", buff);
	L = strlen(buff);
	MMS(dp, -1);
	printf("%d\n", dfs(0, L));
	return 0;
}
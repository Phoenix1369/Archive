#include <cstdio>
const int MAXC = 25;
char buff[MAXC]{ };

int solve()
{
	int cnt[2]{ };
	for(int i = 0; i < 10; ++i)
	{
		int j = i+1;
		int rem = (9-i)/2;
		cnt[i&1] += buff[i]-'0';
		// Other Team Cannot Compensate
		if(	((i & 1) && (cnt[i&1] > cnt[j&1] + rem)) ||
			((j & 1) && (cnt[i&1] > cnt[j&1] + rem + 1)) ) // 2nd Team has extra shot
			return printf("TEAM-%c %d\n", 'A'+(i&1), i+1);
		// Cannot Compensate Other Team
		if(cnt[j&1] > cnt[i&1] + rem)
			return printf("TEAM-%c %d\n", 'A'+(j&1), i+1);
	}
	// Sudden Death
	for(int i = 0; i < 10; i += 2) if(buff[10+i] != buff[11+i])
		return printf("TEAM-%c %d\n", 'A'+(buff[11+i] == '1'), 12+i);
	return puts("TIE");
}

int main()
{
	while(scanf(" %s", buff) != EOF) solve();
	return 0;
}
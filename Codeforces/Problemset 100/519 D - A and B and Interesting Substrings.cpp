#include <cstdio>
#include <cstring>
#include <unordered_map>
typedef long long lld;
const int MAXC = 26;
const int MAXL = 1E5+5;
char buff[MAXL]{ };
int	C[MAXC]{ };
lld	P[MAXL]{ }; // Prefix-Sum Array
std::unordered_map<lld,int> cnt[MAXC]{ };

int main()
{
	for(int i = 0; i < MAXC; ++i)
		scanf("%d", &C[i]);
	scanf(" %s", buff);
	int L = strlen(buff);
	for(int i = 0; i < MAXC; ++i)
		cnt[i].reserve(L+5);
	P[0] = C[buff[0]-'a'];
	for(int i = 1; i < L; ++i)
		P[i] = C[buff[i]-'a'] + P[i-1];
	for(int i = 1; i < L; ++i)
		++cnt[buff[i]-'a'][P[i-1]]; // Insert P[i-1] excludes endpoint
	lld ret=0;
	for(int i = 0; i < L; ++i)
	{
		if(i && !--cnt[buff[i]-'a'][P[i-1]])
			cnt[buff[i]-'a'].erase(P[i-1]);
		// Sum of Zero after subtracting P[i]
		if(cnt[buff[i]-'a'].count(P[i]))
			ret += cnt[buff[i]-'a'].at(P[i]);
	}
	printf("%lld\n", ret);
	return 0;
}

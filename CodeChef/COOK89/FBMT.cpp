#include <cstdio>
#include <map>
#include <string>
typedef std::string str;
const int MAXC = 25;
char buff[MAXC]{ };
std::map<str,int> cnt;
int N, T;

int main()
{
	scanf("%d", &T);
	for(int _ = 0; _ < T; ++_)
	{
		scanf("%d", &N);
		cnt.clear();
		for(int i = 0; i < N; ++i)
		{
			scanf(" %s", buff);
			++cnt[buff];
		}
		if(cnt.empty())
			puts("Draw");
		else if(cnt.size() == 1U)
			puts(cnt.begin()->first.c_str());
		else if(cnt.begin()->second > cnt.rbegin()->second)
			puts(cnt.begin()->first.c_str());
		else if(cnt.begin()->second < cnt.rbegin()->second)
			puts(cnt.rbegin()->first.c_str());
		else
			puts("Draw");
	}
	return 0;
}
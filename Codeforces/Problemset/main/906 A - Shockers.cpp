#include <cstdio>
#include <set>
const int MAXC = 1E5+5;
char buff[MAXC]{ };
std::set<char> cand, must;
int N, ret=0;
char cmd;

int main()
{
	scanf("%d\n", &N);
	for(char c = 'a'; c <= 'z'; c++)
		cand.insert(c);
	for(int _ = 0; _ < N; ++_)
	{
		scanf(" %c", &cmd);
		scanf(" %s", buff);
		switch(cmd)
		{
		case '!':
			if(cand.size() > 1U)
			{
				must.clear();
				for(char * ptr = buff; *ptr; ++ptr)
					must.insert(*ptr);
				for(auto itr = cand.begin(); itr != cand.end();)
					if(must.count(*itr))
						++itr;
					else
						itr = cand.erase(itr);
			}
			else
				++ret;
			break;
		case '.':
			for(char * ptr = buff; *ptr; ++ptr)
				cand.erase(*ptr);
			break;
		case '?':
			if((_ < N-1) && (cand.size() == 1U))
				++ret;
			else
				cand.erase(buff[0]);
			break;
		}
	}
	printf("%d\n", ret);
	return 0;
}
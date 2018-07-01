#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef std::string str;
typedef std::vector<str> vst;
const int MAXC = 20;
char buff[MAXC]{ };
char name[MAXC]{ };
std::unordered_map<str,vst> dir;
int K, N;

int main()
{
	scanf("%d", &N);
	dir.reserve(N);
	for(int i = 0; i < N; ++i)
	{
		scanf(" %s%d", name, &K);
		for(int j = 0; j < K; ++j)
		{
			scanf(" %s", buff);
			dir[name].push_back(buff);
		}
	}
	printf("%u\n", dir.size());
	for(auto& itr: dir)
	{
		std::sort(ALL(itr.second), [&](const str& l, const str& r) {
			return l.size() > r.size();
		});
		for(auto jtr = itr.second.begin(); jtr != itr.second.end(); ++jtr)
		{
			auto ktr = jtr; ++ktr;
			while(ktr != itr.second.end())
			{
				bool suff = true;
				for(int l = 1; l <= (int)ktr->size(); ++l)
					if( ktr->at(ktr->size()-l) != jtr->at(jtr->size()-l))
						suff=false, l=ktr->size();
				if(suff)
					ktr = itr.second.erase(ktr);
				else
					++ktr;
			}
		}
		printf("%s %u", itr.first.c_str(), itr.second.size());
		for(auto jtr: itr.second)
			printf(" %s", jtr.c_str());
		putchar('\n');
	}
	return 0;
}
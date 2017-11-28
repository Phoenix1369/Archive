#include <cstdio>
#include <map>
#include <string>
#include <unordered_map>
typedef std::string str;
const int MAXC = 35;
const int MAXN = 1005;
char buff[MAXC]{ };
int score[MAXN]{ };
std::map<int,int> time[MAXN]{ };
std::unordered_map<str,int> id;
int K=0, N, S;
str ret;

int main()
{
	scanf("%d", &N);
	id.reserve(N);
	for(int i = 1; i <= N; ++i)
	{
		scanf(" %s%d", buff, &S);
		if(!id.count(buff))
			id[buff] = ++K;
		int cur = id.at(buff);
		score[cur] += S;
		if((score[cur] > 0) && !time[cur].count(score[cur]))
			time[cur][score[cur]] = i;
	}
	for(int i = 1; i <= K; ++i)
	{	// Suffix Min
		int M = N+1;
		for(auto mtr = time[i].rbegin(); mtr != time[i].rend(); ++mtr)
			if(M < mtr->second)
				mtr->second = M;
			else
				M = mtr->second;
	}
	int M = -1;
	for(auto itr: id)
		if(	(score[itr.second] >  M) ||
			(score[itr.second] == M &&
				time[itr.second].lower_bound(M)->second <
				time[id.at(ret)].lower_bound(M)->second) )
		{	// Higher Score, Lowest Time
			ret = itr.first;
			M = score[itr.second];
		}
	puts(ret.c_str());
	return 0;
}

#include <cstdio>
#include <cstring>
#include <map>
const int MAXC = 1E6+5;
char buff[MAXC]{ };
std::map<int,int> A;
int all=0, L, ret=0;

int main()
{
	scanf(" %s", buff);
	L = strlen(buff);
	for(int i = 0; i < L; ++i)
		if(!i || (buff[i-1] != buff[i]))
		{
			A[i] = i;
			++all;
		}
		else
			A.rbegin()->second = i;
	while(all > 1)
	{	// Perform Operations
		int beg=A.begin()->first, end=A.rbegin()->second, M=L;
		for(auto itr: A)
			if((itr.first == beg) || (itr.second == end))
				M = std::min(itr.second - itr.first + 1, M);
			else
				M = std::min((itr.second - itr.first + 2) / 2, M);
		for(auto itr = A.begin(); itr != A.end();)
		{	// Deletion
			int l=itr->first, r=itr->second;
			itr = A.erase(itr);
			if(((l == beg) || (r == end)) && (l+M <= r))
				A[l] = r-M;
			else if(l+2*M <= r)
				A[l] = r-M*2;
			else
				--all;
		}
		for(auto itr = A.begin(); itr != A.end();)
		{	// Merge Remnants
			auto ktr = itr; ++ktr;
			if(ktr == A.end()) break;
			if(buff[itr->first] == buff[ktr->first])
			{	// Consecutive Union
				itr->second += ktr->second - ktr->first + 1;
				A.erase(ktr);
				--all;
			}
			else
				itr = ktr;
		}
		ret += M;
	}
	printf("%d\n", ret);
	return 0;
}
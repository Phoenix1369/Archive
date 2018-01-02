#include <cstdio>
#include <vector>
typedef long long lld;
typedef std::vector<int> vin;
int N, ptr[3]{ };
lld ret=0LL;
vin pos[3];

void solve(int i, int k, int& skip, int& prv)
{
	prv = pos[0][i-1];
	while((ptr[k] < (int)pos[k].size()) && (pos[k][ptr[k]] < pos[0][i]))
	{
		skip = std::max(pos[k][ptr[k]]-prv, skip);
		prv = pos[k][ptr[k]++];
	}
	if(prv != pos[0][i-1])
		skip = std::max(pos[0][i]-prv, skip);
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		char C; int p;
		scanf("%d %c", &p, &C);
		int k = (C == 'G') ? 0 : (C == 'R') ? 1 : 2;
		pos[k].push_back(p);
	}
	if(!pos[0].empty())
	{	// Some Green Points
		for(int i = 1; i <= 2; ++i)
			if(!pos[i].empty() && (pos[i][0] < pos[0][0]))
			{	// Preamble
				ret += pos[0][0]-pos[i][0];
				while((ptr[i] < (int)pos[i].size()) && (pos[i][ptr[i]] < pos[0][0]))
					++ptr[i];
			}
		for(int i = 1; i < (int)pos[0].size(); ++i)
		{	// Handle Points
			int blu=-1, prv, red=-1;
			solve(i, 1, red, prv);
			solve(i, 2, blu, prv);
			// Greedily minimize Link
			lld dis=pos[0][i]-pos[0][i-1];
			if((red != -1) && (blu != -1))
				ret += std::min(dis*3-red-blu, dis*2);
			else if(red != -1)
				ret += dis*2-red;
			else if(blu != -1)
				ret += dis*2-blu;
			else
				ret += dis;
		}
		for(int i = 1; i <= 2; ++i)	// Postamble
			if(!pos[i].empty() && (pos[i].back() > pos[0].back()))
				ret += pos[i].back()-pos[0].back();
	}
	else
	{	// Zero Green Points
		for(int i = 1; i <= 2; ++i)
			if(!pos[i].empty())
				ret += pos[i].back()-pos[i].front();
	}
	printf("%lld\n", ret);
	return 0;
}
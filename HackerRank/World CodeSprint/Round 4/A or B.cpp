#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#define ALL(x) (x).begin(), (x).end()
typedef std::string str;
const int MAXC = 5E5+5;
char buff[3][MAXC]{ };
char  out[3][MAXC]{ };
str   inp[3]{ };
int K, L, Q;

inline int htoi(const char& c)
{	// Hex -> Dec
	return (c <= '9') ? (c - '0') : (c - '7');
}

inline char itoh(const int& n)
{	// Dec -> Hex
	return (n <= 9) ? (n + '0') : (n + '7');
}

int main()
{
	scanf("%d", &Q);
	for(int _ = 0; _ < Q; ++_)
	{
		scanf("%d", &K);
		for(int i = 0; i < 3; ++i)
		{
			scanf(" %s", buff[i]);
			inp[i] = buff[i];
		}
		L = std::max(inp[0].size(), std::max(inp[1].size(), inp[2].size()));
		for(int i = 0; i < 3; ++i)
			if(L > (int)inp[i].size())	// Pad Leading Zeroes
				inp[i] = str(L-inp[i].size(), '0') + inp[i];
		int mov = 0;
		for(int i = 0; i < L; ++i)
		{	// Mandatory Changes
			int an = htoi(inp[0][i]);
			int bn = htoi(inp[1][i]);
			int cn = htoi(inp[2][i]);
			for(int bit = 3; bit >= 0; --bit)
			{
				if((cn >> bit) & 1)
				{	// Bit is SET
					if(((an | bn) >> bit) & 1) continue;
					// Neither -> Give to B to minimize A
					bn |= (1 << bit);
					++mov;
				}
				else
				{	// Bit is OFF
					if((an >> bit) & 1)
					{	// Force OFF
						an &= ~(1 << bit);
						++mov;
					}
					if((bn >> bit) & 1)
					{	// Force OFF
						bn &= ~(1 << bit);
						++mov;
					}
				}
			}
			out[0][i] = itoh(an);
			out[1][i] = itoh(bn);
			out[2][i] = itoh(cn);
		}
		if(mov > K) { puts("-1"); continue; }
		for(int i = 0; i < 3; ++i)
			out[i][L] = '\0';
		for(int i = 0; i < L; ++i)
		{
			int an = htoi(out[0][i]);
			int bn = htoi(out[1][i]);
			int cn = htoi(out[2][i]);
			for(int bit = 3; bit >= 0; --bit) if((cn >> bit) & 1)
			{	// Minimize A then B
				if(mov >= K) break;
				if(((an & bn) >> bit) & 1)
				{	// Both SET -> Turn off A
					an &= ~(1 << bit);
					++mov;
				}
				else if(((an >> bit) & 1) && (mov+2 <= K))
				{	// A SET -> Transfer to B
					an &= ~(1 << bit);
					bn |=  (1 << bit);
					mov += 2;
				}
			}
			out[0][i] = itoh(an);
			out[1][i] = itoh(bn);
		}
		int off[2]{ };
		for(int i = 0; i < 2; ++i)
			while(out[i][off[i]] == '0') ++off[i];
		for(int i = 0; i < 2; ++i)
			puts(out[i][off[i]] ? (out[i]+off[i]) : "0");
	}
	return 0;
}
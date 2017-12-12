#include <cstdio>
#include <unordered_map>
const int MAXN = 1E5+5;
const int SQTN = 320;
int	A[MAXN]{ };
std::unordered_map<int,int> F[SQTN]{ };
int	X[MAXN]{ };
int cmd, N, pos, Q, val;

int main()
{
	scanf(" %d%d", &N, &Q);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &A[i]);
		A[i] ^= A[i-1];
		++F[i/SQTN][A[i]];
	}
	for(int _ = 1; _ <= Q; ++_)
	{
		scanf(" %d%d%d", &cmd, &pos, &val);
		int B = pos/SQTN;
		int beg = std::max(B*SQTN, 1); // One-based Indexing Bug
		if(cmd == 1)
		{	// Suffix Range Update
			int old = (A[pos] ^ X[B]) ^ (A[pos-1] ^ X[(pos-1)/SQTN]);
			for(int i = B+1; i*SQTN <= N; ++i)
				X[i] ^= old ^ val;
			if(pos != B*SQTN)
			{
				F[B].clear();
				F[B].reserve(SQTN);
				int end = (B+1)*SQTN;
				for(int i = pos; i < end; ++i)
					A[i] ^= old ^ val;
				for(int i = beg; i < end; ++i)
					++F[B][A[i]];
			}
			else
				X[B] ^= old ^ val;
		}
		else if(cmd == 2)
		{	// Prefix Range Query
			int ret = 0;
			for(int i = 0; i < B; ++i)
				if(F[i].count(X[i] ^ val))
					ret += F[i].at(X[i] ^ val);
			if(pos < (B+1)*SQTN-1)
			{
				for(int i = beg; i <= pos; ++i)
					if((A[i] ^ X[B]) == val)
						++ret;
			}
			else if(F[B].count(X[B] ^ val))
				ret += F[B].at(X[B] ^ val);
			printf("%d\n", ret);
		}
	}
	return 0;
}
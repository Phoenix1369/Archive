#include <cstdio>
#include <unordered_map>
const int MAXN = 1E5+5;
int	A[MAXN]{ };
std::unordered_map<int,int> cnt, nxt[2];
int ace[2], N, prv[2], T;

void swap_pair()
{	// Swaps sole pair with 2 Singletons
	for(int i = 0; i < 2; ++i)
		ace[i] = prv[i] = -1;
	for(int i = 0; i < N; ++i)
		if(A[i] == nxt[0].begin()->first)
			ace[ace[0] != -1] = i;
		else
			prv[prv[0] != -1] = i;
	for(int i = 0; i < 2; ++i)
		std::swap(A[ace[i]], A[prv[i]]);
}

int main()
{
	scanf("%d", &T);
	for(int _ = 0; _ < T; ++_)
	{
		scanf("%d", &N);
		cnt.clear();
		cnt.reserve(N);
		for(int i = 0; i < 2; ++i)
		{
			nxt[i].clear();
			nxt[i].reserve(N);
			ace[i] = prv[i] = 0;
		}
		for(int i = 0; i < N; ++i)
		{
			scanf("%d", &A[i]);
			++cnt[A[i]];
		}
		for(int i = 0; i < N; ++i)
		{	// Compute Rotation Destination
			int B = (cnt.at(A[i]) & 1);
			if(!nxt[B].count(A[i]))
			{
				if(!ace[B]) ace[B] = A[i];
				nxt[B][A[i]] = prv[B];
				prv[B] = A[i];
			}
		}
		// Rotate First Element of Cycle
		if(ace[0]) nxt[0][ace[0]] = prv[0];
		if(ace[1]) nxt[1][ace[1]] = prv[1];
		// Perform Value Rotation
		for(int i = 0; i < N; ++i)
			A[i] = nxt[cnt.at(A[i]) & 1].at(A[i]);
		int ham = N;
		// Corner Cases - Swap Arbitrarily
		if(nxt[1].size() == 1U)
		{	// Only Solo
			for(int i = 0; i < N; ++i)
				if(A[i] == nxt[1].begin()->first)
					std::swap(A[i], A[(i+1)%N]); // Nothing if N = 1.
			if(nxt[0].size() <= 1U) --ham;
		}
		else if(nxt[0].size() == 1U)
		{	// Only Pair
			if(!nxt[1].empty())
				swap_pair();
			else
				ham -= 2;
		}
		printf("%d\n", ham);
		for(int i = 0; i < N; ++i)
			printf("%d ", A[i]);
		putchar('\n');
	}
	return 0;
}
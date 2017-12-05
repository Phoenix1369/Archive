#include <cstdio>
#include <map>
typedef long long lld;
const lld INFN = 1E18;
const int MAXN = 1E5+5;
int	A[MAXN]{ };
int N, Q, T;

std::map<int,int> data[MAXN<<2]{ };

struct MergeSortTree
{
	void build(int F, int L, int R)
	{
		data[F].clear();
		if(L == R)
		{
			++data[F][A[L]];
			return;
		}
		int G=F<<1, M=(L+R)>>1;
		build(G  , L  , M);
		build(G|1, M+1, R);
		for(int i = 0; i < 2; ++i)
			for(auto j: data[G|i])
				data[F][j.first] += j.second;
	}

	lld query(int F, int L, int R, int I, int J)
	{
		if((J < L) || (R < I))
			return -INFN;
		if((I <= L) && (R <= J))
		{
			int apex = 1LL*(A[I]+A[J])/2;
			auto ptr = data[F].lower_bound(apex);
			if(ptr == data[F].end())
			{	// data[F] is not empty
				--ptr;
				return 1LL*(ptr->first-A[I])*(A[J]-ptr->first);
			}
			lld psum = 1LL*(ptr->first-A[I])*(A[J]-ptr->first);
			if(ptr == data[F].begin())
				return psum;
			--ptr;
			lld csum = 1LL*(ptr->first-A[I])*(A[J]-ptr->first);
			return std::max(csum, psum);
		}
		int G=F<<1, M=(L+R)>>1;
		return std::max(query(G, L, M, I, J), query(G|1, M+1, R, I, J));
	}

	void update(int F, int L, int R, int old, int nxt)
	{
		if(!--data[F][A[old]])
			data[F].erase(A[old]);
		++data[F][nxt];
		if(L == R) return;
		int G=F<<1, M=(L+R)>>1;
		if(old <= M)	update(G  , L  , M, old, nxt);
		else		update(G|1, M+1, R, old, nxt);
	}
} mrgtr;

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf(" %d%d", &N, &Q);
		for(int i = 1; i <= N; ++i)
			scanf("%d", &A[i]);
		mrgtr.build(1, 1, N);
		for(int i = 1; i <= Q; ++i)
		{
			int cmd, l, r;
			scanf(" %d%d%d", &cmd, &l, &r);
			switch(cmd)
			{
			case 1: printf("%lld\n", mrgtr.query(1, 1, N, l, r));
				break;
			case 2:
				mrgtr.update(1, 1, N, l, r);
				A[l] = r;
				break;
			}
		}
	}
	return 0;
}

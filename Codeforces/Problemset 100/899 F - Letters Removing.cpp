#include <cstdio>
#include <functional>
#include <vector>
typedef std::vector<int> vin;
const int MAXA = 75;
const int MAXC = 2E5+5;
char buff[MAXC]{ };
int M, N;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define PBDS_RBT(T, U) tree<T, U, std::less<T>, \
	rb_tree_tag, tree_order_statistics_node_update>
PBDS_RBT(int, null_type) A[MAXA]{ };

struct BinaryIndexedTree
{
	int data[MAXC]{ };

	void dec(int x)
	{
		for(int i = x; i <= N; i += i & -i)
			--data[i];
	}

	int  get(int x)
	{
		int sum = 0;
		for(int i = x; i >= 1; i -= i & -i)
			sum += data[i];
		return	sum;
	}
} bintr;

int main()
{
	scanf(" %d%d%s", &N, &M, buff+1);
	for(int i = 1; i <= N; ++i)
		A[buff[i]-'0'].insert(i);
	for(int _ = 1; _ <= M; ++_)
	{
		int l, r; char C;
		scanf("%d%d %c", &l, &r, &C);
		int c=C-'0', lo=0, off=0;
		int hi=A[c].size();
		while(lo < hi)
		{
			int md=(lo+hi)>>1;
			int val = *A[c].find_by_order(md);
			if(val + bintr.get(val) >= l)
				hi = md;
			else
				lo = md+1;
		}
		for(auto itr = A[c].find_by_order(lo);
			(itr != A[c].end()) && (*itr + bintr.get(*itr) + off <= r);
			 itr = A[c].erase(itr))
		{
			buff[*itr] = '\0';
			bintr.dec(*itr);
			++off;
		}
	}
	for(int i = 1; i <= N; ++i)
		if(buff[i]) putchar(buff[i]);
	putchar('\n');
	return 0;
}
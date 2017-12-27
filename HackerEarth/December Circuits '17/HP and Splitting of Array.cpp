#include <cstdio>
#include <cstring>
#include <map>
typedef long long lld;
const int MAXN = 1E5+5;
std::map<int,int> coord;
int A[MAXN], B[MAXN], mgb[MAXN];
int N, T;
lld ret;

void merge(int l, int m, int r)
{
	memcpy(mgb+l, B+l, (sizeof (int)) * (r-l));
	int i=l, j=m, k=l;
	while((i < m) && (j < r))
		if(mgb[i] < mgb[j])
			B[k++] = mgb[i++];
		else
		{
			B[k++] = mgb[j++];
			ret += m-i;
		}
	while(i < m) B[k++] = mgb[i++];
	while(j < r) B[k++] = mgb[j++];
}

void merge_sort(int l, int r)
{
	if(r-l <= 1) return;
	int m=(l+r)>>1;
	merge_sort(l, m);
	merge_sort(m, r);
	merge(l, m, r);
}

int main()
{
	scanf("%d", &T);
	for(int _ = 0; _ < T; ++_)
	{
		coord.clear();
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
		{
			scanf("%d", &A[i]);
			coord[A[i]] = 0;
		}
		int C = 0; ret = 0LL;
		for(auto& ctr: coord)
			ctr.second = C++;
		for(int i = 0; i < N; ++i)
			B[i] = A[i] = coord.at(A[i]);
		merge_sort(0, N);
		for(int i = 0; i < N; ++i)
		{
			ret += N-2*A[i]-1;
			printf("%lld ", ret);
		}
		putchar('\n');
	}
	return 0;
}
#include <cstdio>
#include <set>
const int MAXN = 2E5+5;
int	A[MAXN]{ };
int   len[MAXN]{ };
int   nxt[MAXN]{ };
int   prv[MAXN]{ };
int N, p, ret;

struct CMP {
	bool operator () (const int& l, const int& r) const {
		if(len[l] != len[r])
			return len[l] > len[r];
		return l < r;
	}
};
std::set<int,CMP> heap;

void make_seg(int i)
{
	len[p] = i-p;
	heap.insert(p);
	nxt[p] = i;
	prv[i] = p;
	p = i;
}

int main()
{
	scanf("%d", &N); p=ret=0;
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
		if(i && (A[i] != A[i-1]))
			make_seg(i);
	}
	prv[0] = -1;
	make_seg(N);
	while(!heap.empty())
	{
		int cur = *heap.begin();
		heap.erase(heap.begin());
		if((prv[cur] >= 0) && (nxt[cur] < N) && (A[prv[cur]] == A[nxt[cur]]))
		{	// Merge Segments
			heap.erase(prv[cur]);
			heap.erase(nxt[cur]);
			nxt[prv[cur]]  = nxt[nxt[cur]];
			len[prv[cur]] += len[nxt[cur]];
			prv[nxt[nxt[cur]]] = prv[cur];
			heap.insert(prv[cur]);
		}
		else
		{	// Un-link `cur`
			nxt[prv[cur]] = nxt[cur];
			prv[nxt[cur]] = prv[cur];
		}
		++ret;
	}
	printf("%d\n", ret);
	return 0;
}
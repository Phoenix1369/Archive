#include <cstdio>
#include <cstring>
const int HASH = 10;
const int MAXC = 1E6+5;
const int MOD  = 1E9+7;
char buff[MAXC]{ };
int	H[MAXC]{ };
int L;

int fpm(int b, int e)
{
	int p = 1;
	while(e)
	{
		if(e & 1)
			p = 1LL*b*p % MOD;
		b = 1LL*b*b % MOD;
		e >>= 1;
	}
	return p;
}

void print(int k, int off)
{
	char C = buff[k];
	buff[k] = '\0';
	printf(buff+off);
	buff[k] = C;
}

bool restore(int p, int q)
{
	if((p <= 0) || (p >= q))	return false;
	if((buff[0]=='0') && (p > 1))	return false;
	if((buff[p]=='0') && (q-p > 1))	return false;
	if((buff[q]=='0') && (L-q > 1))	return false;
	int seg2 = (H[q-1] + MOD - 1LL*H[p-1]*fpm(HASH, q-p) % MOD) % MOD;
	int seg3 = (H[L-1] + MOD - 1LL*H[q-1]*fpm(HASH, L-q) % MOD) % MOD;
	if((H[p-1] + seg2) % MOD != seg3) return false;
	print(p, 0); putchar('+');
	print(q, p); putchar('=');
	puts(buff+q);
	return true;
}

int main()
{
	scanf(" %s", buff);
	L = strlen(buff);
	H[0] = buff[0]-'0';
	for(int i = 1; i < L; ++i)
		H[i] = (1LL*H[i-1]*HASH % MOD + buff[i]-'0') % MOD;
	for(int i = L>>1; i < L; ++i)	// Iterate on `=` Location
		if(	restore(L-i  , i) || restore(i*2-L  , i) ||
			restore(L-i-1, i) || restore(i*2-L+1, i) ) break;
	return 0;
}
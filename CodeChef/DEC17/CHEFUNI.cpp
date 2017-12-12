#include <algorithm>
#include <cstdio>
int A, B, C, D[3], T;

int abc() { return A*(D[0]+D[1]+D[2]); }

/* procedure bac()
 * 	Make D[1]=D[0] using B-moves to cancel D[1] with D[2]
 *	* Case #1 (D2 > 2*D[0]): Consume D[0,1] with B-moves, clean up with A-moves
 *	* Case #2: Equalize with B-moves, possible A-move remainder	// */
int bac()
{	// Distribute and Reduce [bac]
	int am = 0;
	int bm = D[1]-D[0];
	int D2 = D[2]-bm;
	if(D2 > 2*D[0])
	{
		bm += 2*D[0];
		am += D2 - 2*D[0];
	}
	else
	{
		bm += D2 - (D2 & 1);	// Reduce D2 -> [0 or 1]
		bm += D[0] - (D2 >> 1);	// Pair off D[0], D[1]
		am += (D2 & 1);
	}
	return B*bm + A*am;
}

int pop_row()
{	// Consume one C-move
	--D[0], --D[1], --D[2];
	int one_cm = bac() + C;
	++D[0], ++D[1], ++D[2];
	return one_cm;
}

// One C-move corrects parity, if needed
// More C-moves are replaced by 2C -> 3B
int bca() { return std::min(bac(), pop_row()); }

int cab() { return C*D[0] + A*(D[1]+D[2]-2*D[0]); }

/* procedure cba()
 *	Flatten with B-moves if possible to maximize C-moves	// */
int cba()
{	// Distribute and Reduce [cba]
	int bm = D[1]-D[0];
	int D2 = D[2]-bm;
	int sum = bac();
	if(D2 <= 2*D[0])
	{	// D[0]-cm = D2-2*cm  <->  cm = D2-D[0]
		int cm = D2 - D[0];
		sum = std::min(C*(D[0]-cm) + B*(bm + 2*cm), sum);
	}
	return std::min(sum, C*D[0] + B*(D[1]-D[0]) + A*(D[2]-D[1]));
}

int chefuni()
{	// Consider Cases
	if((2*A <= B) && (3*A <= C))
		return abc();
	else if((B <= 2*A) && (3*A <= C))
		return bac();
	else if((3*B <= 2*C) && (C <= 3*A))
		return bca();
	else if((C <= 3*A) && (2*A <= B))
		return cab();
	return cba();	// (2*C <= 3*B) && (B <= 2*A)
}

int main()
{
	scanf("%d", &T);
	for(int _ = 0; _ < T; ++_)
	{
		for(int i = 0; i < 3; ++i)
			scanf("%d", &D[i]);
		std::sort(D, D+3);
		scanf(" %d%d%d", &A, &B, &C);
		printf("%d\n", chefuni());
	}
	return 0;
}
#include <cstdio>
char	B[3][3][3][5]{ };
int E=0, X, Y;

int main()
{
	for(int i = 0; i < 3; ++i)
	for(int k = 0; k < 3; ++k)
	for(int j = 0; j < 3; ++j)
		scanf(" %s", B[i][j][k]);
	scanf("%d%d", &Y, &X); --Y, --X;
	for(int i = 0; i < 3; ++i)
	for(int j = 0; j < 3; ++j)
		if(B[Y%3][X%3][i][j] == '.')
			B[Y%3][X%3][i][j] = '!', ++E;
	if(!E)	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
		for(int k = 0; k < 3; ++k)
		for(int l = 0; l < 3; ++l)
			if(B[i][j][k][l] == '.')
				B[i][j][k][l] = '!';
	for(int i = 0; i < 3; ++i, putchar('\n'))
	for(int j = 0; j < 3; ++j, putchar('\n'))
	for(int k = 0; k < 3; ++k)
		printf("%s ", B[i][k][j]);
	return 0;
}
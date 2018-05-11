// Name: ±i®a»ï¡B¼B©¨©_¡B§d¬R§»
// Student No.: B10630020, B10630024, B10630040
// Date: May 6, 2018
// Last Update: May 7, 2018
// Problem statement: Sudoku

#include <iostream>
#include<fstream>
#define N 9


const std::string FILE_NAME = "Question.txt";

void print(char a[N][N]);
char a[N][N] = { 'n','n','n','n','n','n','n','n','n',
'n','n','n','n','n','n','n','n','n',
'n','n','n','n','n','n','n','n','n',
'n','n','n','n','n','n','n','n','n',
'n','n','n','n','n','n','n','n','n',
'n','n','n','n','n','n','n','n','n',
'n','n','n','n','n','n','n','n','n',
'n','n','n','n','n','n','n','n','n',
'n','n','n','n','n','n','n','n','n' };
int main()
{
	print(a);
	system("pause");
	return 0;
}

bool inCol(char a[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (a[row][col] == num)
			return true;
	return false;
}

bool inRow(char a[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (a[row][col] == num)
			return true;
	return false;
}

bool inBox(char a[N][N], int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (a[row + boxStartRow][col + boxStartCol] == num)
				return true;
	return false;
}

// ¦L¥X¯x°}
void print(char a[N][N])
{
	for (int i = 0; i < N; i++)
	{
		printf(" ---------  ---------  ---------\n");
		if (i == 3 || i == 6)
			printf(" ---------  ---------  ---------\n");

		for (int j = 0; j < N; j++)
		{
			if (j == 3 || j == 6)
				printf("¡U");
			printf("¡U%c", a[i][j]);
		}
		printf("¡U\n");
	}
	printf(" ---------  ---------  ---------\n");
}
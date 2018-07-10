// Name: ±i®a»ï¡B¼B©¨©_¡B§d¬R§»
// Student No.: B10630020, B10630024, B10630040
// Date: May 6, 2018
// Last Update: May 15, 2018
// Problem statement: Sudoku

#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h> 
#define N 9

using namespace std;

// prototypes
void print(char a[N][N]);
bool inCol(char a[N][N], int col, int num);
bool inRow(char a[N][N], int row, int num);
bool inBox(char a[N][N], int boxStartRow, int boxStartCol, int num);
bool available(char a[N][N]);
bool isFinished(char a[N][N], int &row, int &col);
bool SolveSudoku(char a[N][N]);
bool isSafe(char a[N][N], int row, int col, int num);

const std::string FILE_NAME = "Question.txt";

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
	ifstream file;
	file.open(FILE_NAME);
	int i = 0, j = 0;
	char input;
	int tmp = 0;
	while (file >> input) {
		a[i][j++] = input;
		if (j == 9)
			j = 0, i++;
		if (i == 9 && j == 0) {
			if (SolveSudoku(a) && available(a))
				print(a);
			else
				printf("%s", "No Solution\n");
			i = 0, j = 0;
		}
	}
	system("pause");
	return 0;
}

bool available(char a[N][N])
{
	for (int i = 1; i <= 9; i++) {
		for (int m = 0; m < 9; m++) {
			if (!inCol(a, m, i) || !inRow(a, m, i))
				return false;
		}
	}
	return true;
}

bool inCol(char a[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (a[row][col] == num + 48)
			return true;
	return false;
}

bool inRow(char a[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (a[row][col] == num + 48)
			return true;
	return false;
}

bool inBox(char a[N][N], int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (a[row + boxStartRow][col + boxStartCol] == num + 48)
				return true;
	return false;
}

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


bool isSafe(char a[N][N], int row, int col, int num)
{
	if (inRow(a, row, num)) {
		return false;
	}
	if (inCol(a, col, num)) {
		return false;
	}
	if (inBox(a, row - row % 3, col - col % 3, num)) {
		return false;
	}
	return true;
}

bool isFinished(char a[N][N], int &row, int &col)
{
	int check[9] = {};
	for (row = 0; row < N; row++) {
		for (col = 0; col < N; col++) {
			if (a[row][col] == 'n') {
				return false;
			}
		}
	}
	return true;
}

bool SolveSudoku(char a[N][N])
{
	int row, col;
	if (isFinished(a, row, col))
	{
		return true;
	}
	for (size_t num = 1; num <= 9; num++)
	{
		if (isSafe(a, row, col, num))
		{
			char temp;
			temp = num + 48;
			a[row][col] = temp;
			if (SolveSudoku(a))
			{
				return true;
			}
		}
		a[row][col] = 'n';
	}
	return false;
}
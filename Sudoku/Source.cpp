// Name: ±i®a»ï¡B¼B©¨©_¡B§d¬R§»
// Student No.: B10630020, B10630024, B10630040
// Date: May 6, 2018
// Last Update: May 15, 2018
// Problem statement: Sudoku

#include <iostream>
#include <fstream>
#define N 9

using namespace std;

// prototypes
void print(char a[N][N]);
bool inCol(char a[N][N], int col, int num);
bool inRow(char a[N][N], int row, int num);
bool inBox(char a[N][N], int boxStartRow, int boxStartCol, int num);
bool trueInput(char a[N][N]);
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
	while (file >> input) {
		a[i][j++] = input;
		if (j == 9)
			j = 0, i++;
	}
	print(a);
	if (!trueInput(a))
		printf("%s" , "No Solution");
	if (SolveSudoku(a))
		print(a);
	else
		printf("%s", "No Solution");
	system("pause");
	return 0;
}

bool trueInput(char a[N][N])
{
	return true;
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

/*	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			check[a[x][y] - 30]--;
			if (check[a[x][y] - 30] < 0) {
				return false;
			}
		}
	}

	check[9] = {};
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			check[a[x][y] - 30]--;
			if (check[a[x][y] - 30] < 0) {
				return false;
			}
		}
	}

	check[9] = {};
	for (int b = 0; b < 3; b++) {
		for (int c = 0; c < 3; c++) {
			for (int d = 3 * b; d < 3 * b + 3; d++) {
				for (int e = 3 * c; e < 3 * c + 3; e++) {
					check[a[d][e] - 30]--;
					if (check[a[d][e] - 30] < 0) {
						return false;
					}
				}
			}
		}
	}*/
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
			temp = (char)num;
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
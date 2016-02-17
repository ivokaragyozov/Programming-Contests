#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool upDiff, rightDiff, downDiff, leftDiff;
int maxScore, moves;

void moveUp(int matrix[][3], int matrixUp[][3], int &cnt1)
{
	cnt1 = 0;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matrixUp[i][j] = matrix[i][j];
		}
	}

	for(int i = 1; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(matrixUp[i - 1][j] == 0)
			{
				matrixUp[i - 1][j] = matrixUp[i][j];
				matrixUp[i][j] = 0;
			}
		}
	}

	for(int j = 0; j < 3; j++)
	{
		for(int i = 1; i < 3; i++)
		{
			if(matrixUp[i][j] == matrixUp[i - 1][j])
			{
				cnt1 += 2 * matrixUp[i - 1][j];
				matrixUp[i - 1][j] = 2 * matrixUp[i - 1][j];
				matrixUp[i][j] = 0;
				break;
			}
		}
	}
	
	for(int i = 1; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(matrixUp[i - 1][j] == 0)
			{
				matrixUp[i - 1][j] = matrixUp[i][j];
				matrixUp[i][j] = 0;
			}
		}
	}
}
void moveRight(int matrix[][3], int matrixRight[][3], int &cnt2)
{
	cnt2 = 0;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matrixRight[i][j] = matrix[i][j];
		}
	}

	for(int i = 0; i < 3; i++)
	{
		for(int j = 1; j >= 0; j--)
		{
			if(matrixRight[i][j + 1] == 0)
			{
				matrixRight[i][j + 1] = matrixRight[i][j];
				matrixRight[i][j] = 0;
			}
		}
	}

	for(int i = 0; i < 3; i++)
	{
		for(int j = 1; j >= 0; j--)
		{
			if(matrixRight[i][j] == matrixRight[i][j + 1])
			{
				cnt2 += 2 * matrixRight[i][j];
				matrixRight[i][j + 1] = 2 * matrixRight[i][j];
				matrixRight[i][j] = 0;
				break;
			}
		}
	}

	for(int i = 0; i < 3; i++)
	{
		for(int j = 1; j >= 0; j--)
		{
			if(matrixRight[i][j + 1] == 0)
			{
				matrixRight[i][j + 1] = matrixRight[i][j];
				matrixRight[i][j] = 0;
			}
		}
	}
}
void moveDown(int matrix[][3], int matrixDown[][3], int &cnt3)
{
	cnt3 = 0;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matrixDown[i][j] = matrix[i][j];
		}
	}

	for(int j = 0; j < 3; j++)
	{
		for(int i = 1; i >= 0; i--)
		{
			if(matrixDown[i + 1][j] == 0)
			{
				matrixDown[i + 1][j] = matrixDown[i][j];
				matrixDown[i][j] = 0;
			}
		}
	}

	for(int j = 0; j < 3; j++)
	{
		for(int i = 1; i >= 0; i--)
		{
			if(matrixDown[i][j] == matrixDown[i + 1][j])
			{
				cnt3 += 2 * matrixDown[i][j];
				matrixDown[i + 1][j] = 2 * matrixDown[i][j]; 
				matrixDown[i][j] = 0;
			}
		}
	}
	
	for(int j = 0; j < 3; j++)
	{
		for(int i = 1; i >= 0; i--)
		{
			if(matrixDown[i + 1][j] == 0)
			{
				matrixDown[i + 1][j] = matrixDown[i][j];
				matrixDown[i][j] = 0;
			}
		}
	}
}
void moveLeft(int matrix[][3], int matrixLeft[][3], int &cnt4)
{
	cnt4 = 0;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matrixLeft[i][j] = matrix[i][j];
		}
	}

	for(int i = 0; i < 3; i++)
	{
		for(int j = 1; j < 3; j++)
		{
			if(matrixLeft[i][j - 1] == 0)
			{
				matrixLeft[i][j - 1] = matrixLeft[i][j];
				matrixLeft[i][j] = 0;
			}
		}
	}

	for(int i = 0; i < 3; i++)
	{
		for(int j = 1; j < 3; j++)
		{
			if(matrixLeft[i][j] == matrixLeft[i][j - 1])
			{
				cnt4 = 2 * matrixLeft[i][j];
				matrixLeft[i][j - 1] = 2 * matrixLeft[i][j];
				matrixLeft[i][j] = 0;
			}
		}
	}
	
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 1; j < 3; j++)
		{
			if(matrixLeft[i][j - 1] == 0)
			{
				matrixLeft[i][j - 1] = matrixLeft[i][j];
				matrixLeft[i][j] = 0;
			}
		}
	}
}
void solve(int currScore, int cntMoves, int matrix[][3], int curr)
{
	if(curr == 11) return;

	cout<<currScore<<" "<<maxScore<<" "<<cntMoves<<endl;

	if(currScore > maxScore)
	{
		maxScore = currScore;
		moves = cntMoves;
	}
	else if(currScore == maxScore && moves > cntMoves) moves = cntMoves;

	int matrixUp[3][3], matrixRight[3][3], matrixDown[3][3], matrixLeft[3][3], cnt1, cnt2, cnt3, cnt4;

	moveUp(matrix, matrixUp, cnt1);
	moveRight(matrix, matrixRight, cnt2);
	moveDown(matrix, matrixDown, cnt3);
	moveLeft(matrix, matrixLeft, cnt4);
	
	upDiff = false;
	rightDiff = false;
	downDiff = false;
	leftDiff = false;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(matrixUp[i][j] != matrix[i][j]) upDiff = true;
			if(matrixRight[i][j] != matrix[i][j]) rightDiff = true;
			if(matrixDown[i][j] != matrix[i][j]) downDiff = true;
			if(matrixLeft[i][j] != matrix[i][j]) leftDiff = true;
		}
	}

	cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<cnt4<<endl;

	if(upDiff) solve(currScore + cnt1, cntMoves + 1, matrixUp, curr + 1);
	if(rightDiff) solve(currScore + cnt2, cntMoves + 1, matrixRight, curr + 1);
	if(downDiff) solve(currScore + cnt3, cntMoves + 1, matrixDown, curr + 1);
	if(leftDiff) solve(currScore + cnt4, cntMoves + 1, matrixLeft, curr + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int matrix[3][3];
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cin>>matrix[i][j];
		}
	}

	solve(0, 0, matrix, 0);

	cout<<maxScore<<" "<<moves<<endl;
	return 0;
}

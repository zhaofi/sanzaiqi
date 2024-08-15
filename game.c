#include "game.h"
#include<stdlib.h>

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}


 void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for(i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j<col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
	}
}


 void PlayerMove(char board[ROW][COL], int row, int col)
 {
	 char ch;
	 int x = 0;
	 int y = 0;
	 while (1) {
		 x = rand() % row;
		 y = rand() % col;
		 if (board[x][y] == ' ') {
			 board[x][y] = '*';
			 break;
		 }
	 }
	 printf("玩家走：>\n");
	 for (int i = 0; i < col; i++) {
		 if (board[0][i] != ' ') {
			 y++;
		 }
		 else {
			 break;
		 }
	 }
	 while (1) {

		 ch = getch();
		 if (ch == 's') {
			 if (board[x + 1][y] == ' ') {
				 board[x][y] = ' ';
				 x++;
				 board[x][y] = '*';
			 }
			 else if (board[x + 2][y] == ' ') {
				 board[x][y] = ' ';
				 x = x+2;
				 board[x][y] = '*';
			 }
		 }

		 if (ch == 'w') {
			 if (board[x - 1][y] == ' ') {
				 board[x][y] = ' ';
				 x--;
				 board[x][y] = '*';
			 }
			 else if (board[x - 2][y] == ' ') {
				 board[x][y] = ' ';
				 x=x-2;
				 board[x][y] = '*';
			 }
		 }

		 if (ch == 'a') {
			 if (board[x][y - 1] == ' ') {
				 board[x][y] = ' ';
				 y--;
				 board[x][y] = '*';
			 }
			 else if (board[x][y - 2] == ' ') {
				 board[x][y] = ' ';
				 y=y-2;
				 board[x][y] = '*';
			 }
		 }

		 if (ch == 'd') {
			 if (board[x][y + 1] == ' ') {
				 board[x][y] = ' ';
				 y++;
				 board[x][y] = '*';
			 }
			 else if (board[x][y + 2] == ' ') {
				 board[x][y] = ' ';
				 y=y+2;
				 board[x][y] = '*';
			 }
		 }
		 system("cls");
		 DisplayBoard(board, ROW, COL);
		 if (ch == 'q') {
			 break;
		 }
	 }
 }

 void ComputerMove(char board[ROW][COL], int row, int col)
 {
	 int x = 0;
	 int y = 0;
	 printf("电脑走棋：>\n");
	 while (1) {
		 x = rand() % row;
		 y = rand() % col;
		 if (board[x][y] == ' ') {
			 board[x][y] = '#';
			 break;
		 }
	 }
 }


 int IsFull(char board[ROW][COL], int row, int col)
 {
	 int i = 0;
	 int j = 0;
	 for (i = 0; i < row; i++) {
		 for (j = 0; j < col; j++) {
			 if (board[i][j] = ' ') {
				 return 0;
			 }
		 }
	 }
	 return 1;
 }

 char IsWin(char board[ROW][COL], int row, int col)
 {
	 int i = 0;
	 for (i = 0; i < row; i++) {
		 if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			 return board[i][1];
		 }
	 }
	 for (i = 0; i < col; i++) {
		 if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ') {
			 return board[1][i];
		 }
	 }
	 if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		 return board[1][1];
	 }
	 if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ') {
		 return board[1][1];
	 }
	 if (1 == IsFull(board, ROW, COL)) {
		 return 'Q';
	 }
	 return 'C';
 }
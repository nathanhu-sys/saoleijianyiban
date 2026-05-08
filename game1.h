#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define easycount 10
void initial(char board[ROWS][COLS],int row,int col,char set);
void displayboard(char board[ROWS][COLS],int row,int col);
void setmind(char board[ROWS][COLS],int count,int row,int col);
void searchmind(char board[ROWS][COLS],char show[ROWS][COLS],int row,int col);
int getcount(char board[ROWS][COLS],int a,int b);
void rapidsearch(char board[ROWS][COLS],char show[ROWS][COLS],int x,int y,int row,int col);
int issuccessful(char show[ROWS][COLS],int row,int col);
void mark(char show[ROWS][COLS],int row,int col);
void deletemark(char show[ROWS][COLS],int row,int col);

#include"game1.h"
void initial(char board[ROWS][COLS],int row,int col,char set){
	int i=0;
	int j=0;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			board[i][j]=set;
		}
	}
}
void displayboard(char board[ROWS][COLS],int row,int col){
	int j=0;
	int i=0;
	printf("----------扫雷游戏-------------\n");
	for(j=0;j<=col;j++){
		printf("%d",j);
	}
	printf("\n");
	for(i=1;i<=row;i++){
		printf("%d",i);
		for(j=1;j<=col;j++){
			printf("%c",board[i][j]);
		}
		printf("\n");
	}
	printf("----------扫雷游戏-------------\n");
}
void setmind(char board[ROWS][COLS],int count,int row,int col){
	int x=0;
	int y=0;
	while(count){
		x=rand()%row+1;
		y=rand()%col+1;
		if(board[x][y]=='0'){
			board[x][y]='1';
			count--;
		}
	}
}
int getcount(char board[ROWS][COLS],int a,int b){
	return(board[a-1][b-1]+board[a-1][b]+board[a-1][b+1]+board[a][b-1]+board[a][b+1]+board[a+1][b-1]+board[a+1][b]+board[a+1][b+1]-8*'0');
}
void searchmind(char board[ROWS][COLS],char show[ROWS][COLS],int row,int col){
	int x=0;
	int y=0;
	int win=0;
	int p=0;
    while(issuccessful(show,row,col)){
    		printf("请输入要查的坐标->");
	scanf("%d %d",&x,&y);
	    if(x>=1&&x<=row&&y>=1&&y<=col){
	    	if(show[x][y]!='*'){
	    		printf("已选择过，请再来");
			}
			else{
				if(board[x][y]=='1'){
					printf("已中雷拜拜了您嘞\n");
					displayboard(board,ROW,COL); 
					break; 
				}
				else{
					rapidsearch(board,show,x,y,row,col);
					displayboard(show,ROW,COL);
					printf("请选择操作：0.标记 1.删除标记 2或其他.继续");
					scanf("%d",&p);
					switch(p){
						case 0:
							mark(show,row,col);
							break;
							case 1:
								deletemark(show,row,col);
								break;
								default:
									break;
					} 
				}
			}
		}
		else{
			printf("越界访问不成功");
		}
	}
	if(!issuccessful(show,row,col)){
		printf("恭喜你排雷成功");
		displayboard(board,ROW,COL);
	}
}
void rapidsearch(char board[ROWS][COLS],char show[ROWS][COLS],int x,int y,int row,int col){
	int i=0;
	int j=0;
	char ch=0;
	if(x>=1&&x<=row&&y>=1&&y<=col){
		int count=getcount(board,x,y);
		if(count==0){
			show[x][y]=' ';
					for(i=x-1;i<=x+1;i++){
			for(j=y-1;j<=y+1;j++){
				if(show[i][j]=='*'){
					rapidsearch(board,show,i,j,row,col);
				}
			}
		}
		}

		else{
			show[x][y]=count+'0';
		}
	}
} 
int issuccessful(char show[ROWS][COLS],int row,int col){
	int i=0;
	int j=0;
	int sum=0;
	for(i=1;i<=row;i++){
		for(j=1;j<col;j++){
			if(show[i][j]=='*'||show[i][j]=='@'){
				sum++;
			}
		}
	}
	if(sum==easycount){
		return 0;
	}
	else{
		return 1;
	}
}
void mark(char show[ROWS][COLS],int row,int col){
	int a=0;
	int b=0;
	do{
		printf("请输入你的选择，退出选0 0，删除选0 1\n");
		scanf("%d %d",&a,&b);
		if(a==0&&b==1){
			deletemark(show,row,col);
		}
		
			if(a!=0&&b!=0){
				if(show[a][b]=='*'){
					show[a][b]='@';
					displayboard(show,row,col);
				}
			}
		else{
			break;
		}
	}while(1);
}
void deletemark(char show[ROWS][COLS],int row,int col){
	int x=0;
	int y=0;
	do{
		printf("请输入你要删的标记\n");
		scanf("%d %d",&x,&y);
		if(x>=1&&x<=row&&y>=1&&y<=col){
			if(show[x][y]=='@'){
				show[x][y]='*';
				displayboard(show,row,col);
			}
			else{
				printf("该坐标没有标记，请重选\n");
			}
			
		}
		else{
			printf("坐标越界请重新输入\n"); 
			break; 
		}
	}while(1);
}

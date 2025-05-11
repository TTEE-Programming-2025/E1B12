#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h> 
char seatB[9][9];
//show the seat 
void seatshow(char a[9][9]){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
}
//for a
void optionA(char seat[9][9]){
	system("CLS");
	srand(time(NULL));
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			seat[i][j] = '_';
		}
	}
	int count = 0;
	while(count < 10){
    	int a = rand() % 9;
    	int b = rand() % 9;
    	if(seat[a][b] != '*'){
        	seat[a][b] = '*';
        	count++; // 只在成功放置一顆 * 才增加 count
    	}
	}
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			seatB[i][j] = seat[i][j];
		}
	}
	seatshow(seat);
}
 
int main(void){
	int key,time=0,j,k,l,num;//定義變數，分別代表:密碼/次數/迴圈/迴圈/迴圈/b的輸入數字 
	char n,ch1;//定義變數，分別是一開始輸入的abc/a c輸入的字元 
	char seat[9][9];

	printf("請輸入4位數密碼:");
	do{
		
		
		scanf("%d",&key); 
		fflush(stdin);
		if(key==2025){//確認密碼是否正確 
			break;
		}
		if(time>1){//檢查輸入次數，輸入錯誤3次結束 
			printf("錯誤!\n");
			return 0;
		}
		else{//輸入錯誤時的提醒 
			printf("請再次輸入4位數密碼:");
		}
		time++;
	}while(1);
	system("CLS");
	//the menu
	do{
		printf("----[Booking System]----\n");
		printf("|a. Available seats    |\n");//主介面 
		printf("|b. Arrange for you    |\n");
		printf("|c. Choose by yourself |\n");
		printf("|d. Exit               |\n");
		printf("------------------------\n");
		printf("Please enter a or b or c or d:");
		scanf("%c",&n);
		fflush(stdin);
		if(n=='a'||n=='A'){//輸入的是否是a 
			optionA(seat);
			printf("請按下任意鍵，回到主選單\n");
			getch();
			system("CLS");
			continue;//回到主介面	
		}
		/*if(n=='b'||n=='B'){//輸入的是否是b
			optionB(seatB);		
		}
		if(n=='c'||n=='C'){
			optionC(seatB);
		}*/
		if(n=='d'||n=='D'){//輸入的是否是c
			printf("Continue?(y/n):");
			do{//確認輸入
				scanf("%c",&ch1);
				fflush(stdin);
				switch(ch1){
					case 'y':
					case 'Y':
						system("CLS");
						break;
					case 'N':
					case 'n':
						printf("程式結束");
						return 0;
					default:
						printf("錯誤!，請重輸:");
						continue;
				}break;
			}while(1);
			continue;	
		}
		else{//輸入的不是a b c
			printf("錯誤!請重新輸入\n");
			continue;
		}
	}while(1);

	
	return 0;
}

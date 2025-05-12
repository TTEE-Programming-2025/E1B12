#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
char seatB[9][9];//全域變數，儲存一開始輸入a時的座位表 
//show the seat 
void seatshow(char a[9][9]) {
    int i, j;
    printf("\\123456789\n");
    for(i = 0; i < 9; i++) {
        printf("%d", 9 - i);
        for(j = 0; j < 9; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}
//for a廢案 
/*void optionA(char seat[9][9]) {
    system("CLS");
    srand(time(NULL));
    int i, j;
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            seat[i][j] = '-';
        }
    }
    int count = 0;
    while(count < 10) {
        int a = rand() % 9;
        int b = rand() % 9;
        if(seat[a][b] != '*') {
            seat[a][b] = '*';
            count++;// 只在成功放置一顆 * 才增加 count
        }
    }
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            seatB[i][j] = seat[i][j];
        }
    }
    printf("現有座位如下：\n");
    seatshow(seat);
}*/
//for b 
void optionB(char seat[9][9]) {
    int need,i,j,k;
    printf("How many seats do you need? (1~4): ");
    scanf("%d", &need);
    if(need < 1 || need > 4) {
        printf("錯誤數量，請回主選單。\n");
        return;
    }
    else if(need>=1&&need<=4){
    	switch(need){
    		case 1:
    			while(1){
    				int a = rand()%9;
    				int b = rand()%9;
    				if(seat[a][b]!='*'){
    					seat[a][b]='@';
					}
					break; 
				}
				break;
			case 2:
				while(1){
                    int a=rand()%9;
                    int b=rand()%8;
                    if(seat[a][b]!='*'&&seat[a][b+1]!='*'){
                        seat[a][b]='@'; 
                        seat[a][b+1]='@'; 
                        break;
                    }
                }
                break;
            case 3:
                while(1){
                    int a=rand()%9;
                    int n=rand()%7;
                    if(seat[a][n]=='-'&&seat[a][n+1]=='-'&&seat[a][n+2]=='-'){
                        seat[a][n]='@'; 
                        seat[a][n+1]='@';
                        seat[a][n+2]='@'; 
                        break;
                	}     
            	}
                break;
			case 4:
    			while(1) {
        			k = rand() % 2;
        			if (k == 0) {
            			int a = rand() % 9;
            			int b = rand() % 6;
            			if (seat[a][b] == '-' && seat[a][b+1] == '-' &&
                			seat[a][b+2] == '-' && seat[a][b+3] == '-') {
                			for (i = b; i <= b + 3; i++) {
                    			seat[a][i] = '@';
                			}
                			break; // ? 正確：跳出 while(1)
            			}
        			} 
					else {
            			int a = rand() % 8;
            			int b = rand() % 8;
            			if (seat[a][b] == '-' && seat[a][b+1] == '-' &&
                			seat[a+1][b] == '-' && seat[a+1][b+1] == '-') {
                			seat[a][b] = '@';
                			seat[a][b+1] = '@';
                			seat[a+1][b] = '@';
                			seat[a+1][b+1] = '@';
                			break; 
            			}
        			}
    			}
    			break;  
		}
	}
	printf("系統建議座位如下：\n");
    seatshow(seat);
    printf("是否滿意此安排？(y/n): ");
    char ch;
    fflush(stdin);
    scanf(" %c", &ch);
    if(ch == 'y' || ch == 'Y') {
        for(i = 0; i < 9; i++) {
            for(j = 0; j < 9; j++) {
                if(seat[i][j] == '@') seat[i][j] = '*';
            }
        }
    } 
	else{
        for(i = 0; i < 9; i++) {
            for(j = 0; j < 9; j++) {
                if(seat[i][j] == '@') seat[i][j] = '-';
            }
        }
    }
}
//for c
void optionC(char seat[9][9]) {
    int i,j,a,b;
    char ch;
	do{
		printf("請輸入座位(格式如1-2):"); 
		scanf("%d%c%d",&a,&ch,&b);
		if(a>9||a<1||b>9||b<1){
			printf("錯誤，請重新輸入\n");
			continue;
		}
		if(ch!='-'){
			printf("錯誤，請重新輸入\n");
			continue;
		}
		if(seat[9-a][b-1]=='*'){
			printf("已選，請重新輸入\n");
		}
		else{
			seat[9-a][b-1]='@';
			break;
		}
	}while(1);
    // 顯示預覽座位圖
    seatshow(seat);
    printf("若選擇正確，請按任意鍵繼續...\n");
    getch();

    // 確認後將選擇寫入主座位表
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (seat[i][j] == '@') {
                seat[i][j] = '*';
            }
        }
    }
}
int main(void) {
    srand(time(NULL));
	int key, time = 0;//定義變數，分別代表:密碼/次數
    char n, ch1;
    char seat[9][9];
    int i, j;
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            seat[i][j] = '-';
        }
    }
    int count = 0;
    while(count < 10) {
        int a = rand() % 9;
        int b = rand() % 9;
        if(seat[a][b] != '*') {
            seat[a][b] = '*';
            count++;// 只在成功放置一顆 * 才增加 count
        }
    }
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            seatB[i][j] = seat[i][j];
        }
    }
    // 個人風格畫面
    printf("==============\n");
	printf("==============\n");
	printf("E1B12\n");
	
    printf("請輸入4位數密碼: ");
    do {
        scanf("%d", &key);
        fflush(stdin);
        if(key == 2025){//確認密碼是否正確
        	break;
		}
        if(time >= 2){//檢查輸入次數，輸入錯誤3次結束
            printf("錯誤三次，程式結束。\n");
            return 0;
        } 
		else{//輸入錯誤時的提醒
            printf("密碼錯誤，請重新輸入: ");
            time++;
        }
    } while(1);

    system("CLS");

    do {//主介面 
        printf("----------[Booking System]----------\n");
        printf("| a. Available seats                |\n");
        printf("| b. Arrange for you                |\n");
        printf("| c. Choose by yourself             |\n");
        printf("| d. Exit                           |\n");
        printf("------------------------------------\n");
        printf("Please enter a or b or c or d: ");
        
        scanf(" %c", &n);
        fflush(stdin);
        if(n == 'a' || n == 'A') {//輸入的是否是a
            seatshow(seatB);
            printf("請按任意鍵返回主選單...\n");
            getch();
            system("CLS");
            continue;
        }
        if(n == 'b' || n == 'B') {//輸入的是否是b
            optionB(seatB);
            printf("請按任意鍵返回主選單...\n");
            getch();
            system("CLS");
            continue;
        }
        if(n == 'c' || n == 'C') {//輸入的是否是c
            optionC(seatB);
            system("CLS");
            continue;
        }
        if(n == 'd' || n == 'D') {//輸入的是否是d
            printf("Continue? (y/n): ");
            do {
                scanf(" %c", &ch1);
                fflush(stdin);
                if(ch1 == 'y' || ch1 == 'Y') {
                    system("CLS");
                    break;
                } else if(ch1 == 'n' || ch1 == 'N') {
                    printf("程式結束。\n");
                    return 0;
                } else {
                    printf("錯誤輸入，請重新輸入(y/n): ");
                }
            } while(1);
            continue;
        } 
		else {//不是abc
            printf("輸入錯誤，請重新輸入。\n");
            continue;
        }
    } while(1);

    return 0;
}


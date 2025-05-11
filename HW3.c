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
//for a
void optionA(char seat[9][9]) {
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
}
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
                k=rand()%2;
                if(k == 0){
        				int a=rand()%9;
                    	int b=rand()%6;
                    	if(seat[a][b]=='-'&&seat[a][b+1]=='-'&&seat[a][b+2]=='-'&&seat[a][b+3]=='-'){
                        	for(i=b;i<=b+3;i++){
                        		seat[a][i]='@';
							}
                        	break;
                    	}	
    				} 
					else if(k == 1){
        				int a=rand()%8;
                    	int b=rand()%8;
                    	if(seat[a][b]=='-'&&seat[a][b+1]=='-'&&seat[a+1][b]=='-'&&seat[a+1][b+1]=='-'){
                        	seat[a][b]='@'; 
                        	seat[a][b+1]='@';
                        	seat[a+1][b]='@';
                        	seat[a+1][b+1]='@'; 
                        	break;
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
/*void optionC(char seat[9][9]) {
    int a,b,i,j;
    char input[10];
    int row, col;
    char temp[9][9];
    for(i = 0; i < 9; i++){
    	for(j = 0; j < 9; j++){
    		temp[i][j] = seat[i][j];
		}
	} 

    printf("請依格式輸入座位 (例：1-2)，結束請輸入 x：\n");
    while(1) {
        scanf("%s", input);
        if(input[0] == 'x' || input[0] == 'X'){
			break;
		}
		
        if(sscanf(input, "%d-%d", &a, &b) != 2 || a < 1 || a > 9 || b < 1 || b > 9) {
            printf("格式錯誤或超出範圍，請重新輸入。\n");
            continue;
        }
        row = 9 - a;
        col = b - 1;
        if(temp[row][col] == '-') {
            temp[row][col] = '@';
        } else {
            printf("座位 %d-%d 已被選，請重新輸入。\n", a, b);
        }
    }
    seatshow(temp);
    printf("若選擇正確，請按任意鍵繼續...\n");
    getch();
    // 更新已選座位為 *
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            if(temp[i][j] == '@') {
            	seat[i][j] = '*';	
			}
        }
    }
}*/ 
void optionC(char seat[9][9]) {
    char input[100];
    char *token;
    int a, b, row, col;
    int i, j;
    char temp[9][9];
    int valid;

    while (1) {
        // 每次先複製一份原本的座位圖
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                temp[i][j] = seat[i][j];
            }
        }

        printf("請依格式輸入座位（例：1-2 3-4 5-6），按 Enter 結束：\n");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // 去除換行字元

        valid = 1; // 預設輸入有效

        // 逐個檢查座位格式與狀態
        token = strtok(input, " ");
        while (token != NULL) {
            if (sscanf(token, "%d-%d", &a, &b) != 2 || a < 1 || a > 9 || b < 1 || b > 9) {
                printf("輸入「%s」格式錯誤或超出範圍。\n", token);
                valid = 0;
                break;
            }
            row = 9 - a;
            col = b - 1;
            if (temp[row][col] != '-') {
                printf("座位 %d-%d 已被選，請重新輸入。\n", a, b);
                valid = 0;
                break;
            }
            temp[row][col] = '@'; // 標記選位
            token = strtok(NULL, " ");
        }

        if (valid) break; // 所有輸入都合法才跳出迴圈，否則重輸
    }

    // 顯示預覽座位圖
    seatshow(temp);
    printf("若選擇正確，請按任意鍵繼續...\n");
    getch();

    // 確認後將選擇寫入主座位表
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (temp[i][j] == '@') {
                seat[i][j] = '*';
            }
        }
    }
}
int main(void) {
    int key, time = 0;//定義變數，分別代表:密碼/次數
    char n, ch1;
    char seat[9][9];

    // 個人風格畫面
    system("CLS");
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
            optionA(seat);
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


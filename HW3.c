#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
char seatB[9][9];//A global variable to store the seating chart when 'a' is first entered.
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
        printf("Incorrect number. Returning to the main menu.\n");
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
                    int b=rand()%8;//Prevent seat selection overflow.
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
                    int n=rand()%7;//Prevent seat selection overflow.
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
            			int b = rand() % 6;//Prevent seat selection overflow.
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
	printf("The system suggests the following seats:\n");
    seatshow(seat);
    printf("Are you satisfied with this arrangement?(y/n): ");
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
    int i,j,a,b,num;
    char ch;
    printf("Please enter how many seats you want:");
    scanf("%d",&num);
    for(i=1;i<=num;i++){
    	do{
			printf("Please enter a seat (format: 1-2):"); 
			scanf("%d%c%d",&a,&ch,&b);
			if(a>9||a<1||b>9||b<1){
				printf("Error, please re-enter.\n");
				continue;
			}
			if(ch!='-'){
				printf("Error, please re-enter.\n");
				continue;
			}
			if(seat[9-a][b-1]=='*'){
				printf("Already selected, please re-enter.\n");
			}
			else{
				seat[9-a][b-1]='@';
				break;
			}
		}while(1);
	}
	
    // Display preview of seating chart.
    seatshow(seat);
    printf("If correct, press any key to continue...\n");
    getch();

    // After confirmation, write the selection to the main seating chart.
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
	int key, time = 0;//Define variables to represent: password / count.
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
            count++;// Increment the count only when a * is successfully placed.
        }
    }
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            seatB[i][j] = seat[i][j];
        }
    }
    // Personalized interface
    printf("===================\n");
	printf("===================\n");
	printf("E1B12 password:2025\n");
	for(i = 0; i < 17; i++) {
        printf("===================\n");
    }
    printf("Please enter a 4-digit password:");
    do {
        scanf("%d", &key);
        fflush(stdin);
        if(key == 2025){//Check if the password is correct.
        	break;
		}
        if(time >= 2){//Check the number of attempts. End after 3 incorrect attempts.
            printf("Incorrect three times, the program will terminate.\n");
            return 0;
        } 
		else{//Reminder for incorrect input.
            printf("Incorrect password, please re-enter:");
            time++;
        }
    } while(1);

    system("CLS");

    do {//Main interface 
        printf("----------[Booking System]----------\n");
        printf("| a. Available seats                |\n");
        printf("| b. Arrange for you                |\n");
        printf("| c. Choose by yourself             |\n");
        printf("| d. Exit                           |\n");
        printf("------------------------------------\n");
        printf("Please enter a or b or c or d: ");
        
        scanf(" %c", &n);
        fflush(stdin);
        if(n == 'a' || n == 'A') {//Is the input 'a'?
            seatshow(seatB);
            printf("Press any key to return to the main menu...\n");
            getch();
            system("CLS");
            continue;
        }
        if(n == 'b' || n == 'B') {//Is the input 'b'?
            optionB(seatB);
            printf("Press any key to return to the main menu...\n");
            getch();
            system("CLS");
            continue;
        }
        if(n == 'c' || n == 'C') {//Is the input 'c'?
            optionC(seatB);
            system("CLS");
            continue;
        }
        if(n == 'd' || n == 'D') {//Is the input 'd'?
            printf("Continue? (y/n): ");
            do {
                scanf(" %c", &ch1);
                fflush(stdin);
                if(ch1 == 'y' || ch1 == 'Y') {
                    system("CLS");
                    break;
                } else if(ch1 == 'n' || ch1 == 'N') {
                    printf("Program terminated.\n");
                    return 0;
                } else {
                    printf("Incorrect input, please re-enter (y/n):");
                }
            } while(1);
            continue;
        } 
		else {//not abc
            printf("Incorrect input, please re-enter.\n");
            continue;
        }
    } while(1);

    return 0;
}


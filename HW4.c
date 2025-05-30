#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 10
int n;
struct data{
	char name[99];
	char id[7];
	int math;
	int physics;
	int english;
	float avg;
}student[MAX];
void swap(struct data *a, struct data *b) {//交換的函式 
    struct data temp = *a;
    *a = *b;
    *b = temp;
}
//for a
void optionA(){
	int i,j,check=0;
	system("CLS");
    do{
    	printf("請輸入學生人數:(5~10):");
    	scanf("%d",&n);
    	if(n<5||n>10){
    		printf("錯誤!");
		}
	}while(n<5||n>10);//只能輸出5~10為哦! 
    for(i=0;i<n;i++){//依序輸入資料 
    	printf("請輸入第%d位學生的姓名:",i+1);
    	scanf("%s",student[i].name);
    	do{
    		check=0;
    		printf("輸入第%d位學生的學號:",i+1);
    		scanf("%s",student[i].id);
    		if(strlen(student[i].id) != 6) {
                printf("錯誤! 學號必須為 6 位數字。\n");
                check = 1;
            } 
			else{
                for (j = 0; j < 6; j++) {
                    if (student[i].id[j] < '0' || student[i].id[j] > '9') {
                        printf("錯誤! 學號中不能包含英文字母。\n");
                        check = 1;
                        break;
                    }
                }
            }
		}while(check==1);
		do{
			check=0;
    		printf("輸入第%d位學生的數學成績:",i+1);
    		scanf("%d",&student[i].math);
    		if(student[i].math<0||student[i].math>100){
    			printf("錯誤!");
    			check=1;
			}
		}while(check==1);
		check=0;
		do{
			check=0;
    		printf("輸入第%d位學生的物理成績:",i+1);
    		scanf("%d",&student[i].physics);
    		if(student[i].physics<0||student[i].physics>100){
    			printf("錯誤!");
    			check=1;
			}
		}while(check==1);
		check=0;
		do{
			check=0;
    		printf("輸入第%d位學生的英文成績:",i+1);
    		scanf("%d",&student[i].english);
    		if(student[i].english<0||student[i].english>100){
    			printf("錯誤!");
    			check=1;
			}
		}while(check==1);
		student[i].avg=(student[i].math+student[i].physics+student[i].english)/3;//計算並記錄平均 
	}
}
//for b 
void optionB(){
	int i;
	system("CLS");
	printf("%-8s %-10s %-6s %-6s %-6s %-6s\n", "姓名", "學號", "數學", "物理", "英文", "平均");//讓輸出對齊的好方法 
    for(i=0;i<n;i++){
    	printf("%-8s %-10s %-6d %-6d %-6d %-6.1f\n",student[i].name,student[i].id,student[i].math,student[i].physics,student[i].english,student[i].avg);
	}
	
}
//for c
void optionC() {
	int i;
    system("CLS");
    char str[99];
    int check=0;
    printf("輸入學生的姓名:");
    scanf("%s",str);
    for(i=0;i<n;i++){
    	if(strcmp(str,student[i].name)==0){//比較姓名 
    		printf("%-8s %-10s %-6s %-6s %-6s %-6s\n", "姓名", "學號", "數學", "物理", "英文", "平均");
    		printf("%-8s %-10s %-6d %-6d %-6d %-6.1f\n",student[i].name,student[i].id,student[i].math,student[i].physics,student[i].english,student[i].avg);
			check=1;
			break;
		} 
	}
	if(check=0){
		printf("查無此人");
	}
}
//for d
void optionD() {
    // 排序：從大到小
    system("CLS");
	int i,j;
	printf("大到小:\n");
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (student[j].avg < student[j + 1].avg) {
                swap(&student[j], &student[j + 1]);
            }
        }
    }

    printf("%-8s %-10s %-6s\n", "姓名", "學號", "平均");
    for (i = 0; i < n; i++) {
        printf("%-8s %-10s %-6.1f\n", student[i].name, student[i].id, student[i].avg);
    }
}
int main(void) {
	int i,key, time = 0;//Define variables to represent: password / count.
    char n, ch1;
    int count = 0;
    // Personalized interface
    printf("℅★☆♁℅★☆♁℅★☆♁℅★☆♁℅★☆♁℅\n");
	printf("℅★☆♁℅★☆♁℅★☆♁℅★☆♁℅★☆♁℅\n");
	printf("E1B12 password:2025\n");
	for(i = 0; i < 17; i++) {
        printf("℅★☆♁℅★☆♁℅★☆♁℅★☆♁℅★☆♁℅\n");
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
        printf("| a. Enter student grades           |\n");
        printf("| b. Display student grades         |\n");
        printf("| c. Search for student grades      |\n");
        printf("| d. Grade ranking                  |\n");
        printf("| e. Exit syste                     |\n");
        printf("------------------------------------\n");
        printf("Please enter a or b or c or d or e: ");
        
        scanf(" %c", &n);
        fflush(stdin);
        if(n == 'a' || n == 'A') {//Is the input 'a'?
        	optionA();
            printf("Press any key to return to the main menu...\n");
            getch();
            system("CLS");
            continue;
        }
        if(n == 'b' || n == 'B') {//Is the input 'b'?
            optionB();
            printf("Press any key to return to the main menu...\n");
            getch();
            system("CLS");
            continue;
        }
        if(n == 'c' || n == 'C') {//Is the input 'c'?
            optionC();
            printf("Press any key to return to the main menu...\n");
            getch();
            system("CLS");
            continue;
        }
        if(n == 'd' || n == 'D') {//Is the input 'c'?
            optionD();
            printf("Press any key to return to the main menu...\n");
            getch();
            system("CLS");
            continue;
        }
        if(n == 'e' || n == 'E') {//Is the input 'd'?
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
		else {//not abcd
            printf("Incorrect input, please re-enter.\n");
            continue;
        }
    } while(1);

    return 0;
}
/*在這次的作業中，我熟悉了結構這個酷東西，
這個東東除了讓我不用設太多變數外，也讓我很
清楚的知道哪個變數的用途是甚麼，不會混淆。*/ 

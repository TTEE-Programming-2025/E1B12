#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
char seatB[9][9];//�����ܼơA�x�s�@�}�l��Ja�ɪ��y��� 
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
            count++;// �u�b���\��m�@�� * �~�W�[ count
        }
    }
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            seatB[i][j] = seat[i][j];
        }
    }
    printf("�{���y��p�U�G\n");
    seatshow(seat);
}
//for b 
void optionB(char seat[9][9]) {
    int need,i,j,k;
    printf("How many seats do you need? (1~4): ");
    scanf("%d", &need);
    if(need < 1 || need > 4) {
        printf("���~�ƶq�A�Ц^�D���C\n");
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
	printf("�t�Ϋ�ĳ�y��p�U�G\n");
    seatshow(seat);
    printf("�O�_���N���w�ơH(y/n): ");
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

    printf("�Ш̮榡��J�y�� (�ҡG1-2)�A�����п�J x�G\n");
    while(1) {
        scanf("%s", input);
        if(input[0] == 'x' || input[0] == 'X'){
			break;
		}
		
        if(sscanf(input, "%d-%d", &a, &b) != 2 || a < 1 || a > 9 || b < 1 || b > 9) {
            printf("�榡���~�ζW�X�d��A�Э��s��J�C\n");
            continue;
        }
        row = 9 - a;
        col = b - 1;
        if(temp[row][col] == '-') {
            temp[row][col] = '@';
        } else {
            printf("�y�� %d-%d �w�Q��A�Э��s��J�C\n", a, b);
        }
    }
    seatshow(temp);
    printf("�Y��ܥ��T�A�Ы����N���~��...\n");
    getch();
    // ��s�w��y�쬰 *
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
        // �C�����ƻs�@���쥻���y���
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                temp[i][j] = seat[i][j];
            }
        }

        printf("�Ш̮榡��J�y��]�ҡG1-2 3-4 5-6�^�A�� Enter �����G\n");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // �h������r��

        valid = 1; // �w�]��J����

        // �v���ˬd�y��榡�P���A
        token = strtok(input, " ");
        while (token != NULL) {
            if (sscanf(token, "%d-%d", &a, &b) != 2 || a < 1 || a > 9 || b < 1 || b > 9) {
                printf("��J�u%s�v�榡���~�ζW�X�d��C\n", token);
                valid = 0;
                break;
            }
            row = 9 - a;
            col = b - 1;
            if (temp[row][col] != '-') {
                printf("�y�� %d-%d �w�Q��A�Э��s��J�C\n", a, b);
                valid = 0;
                break;
            }
            temp[row][col] = '@'; // �аO���
            token = strtok(NULL, " ");
        }

        if (valid) break; // �Ҧ���J���X�k�~���X�j��A�_�h����
    }

    // ��ܹw���y���
    seatshow(temp);
    printf("�Y��ܥ��T�A�Ы����N���~��...\n");
    getch();

    // �T�{��N��ܼg�J�D�y���
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (temp[i][j] == '@') {
                seat[i][j] = '*';
            }
        }
    }
}
int main(void) {
    int key, time = 0;//�w�q�ܼơA���O�N��:�K�X/����
    char n, ch1;
    char seat[9][9];

    // �ӤH����e��
    system("CLS");
    printf("�п�J4��ƱK�X: ");
    do {
        scanf("%d", &key);
        fflush(stdin);
        if(key == 2025){//�T�{�K�X�O�_���T
        	break;
		}
        if(time >= 2){//�ˬd��J���ơA��J���~3������
            printf("���~�T���A�{�������C\n");
            return 0;
        } 
		else{//��J���~�ɪ�����
            printf("�K�X���~�A�Э��s��J: ");
            time++;
        }
    } while(1);

    system("CLS");

    do {//�D���� 
        printf("----------[Booking System]----------\n");
        printf("| a. Available seats                |\n");
        printf("| b. Arrange for you                |\n");
        printf("| c. Choose by yourself             |\n");
        printf("| d. Exit                           |\n");
        printf("------------------------------------\n");
        printf("Please enter a or b or c or d: ");
        scanf(" %c", &n);
        fflush(stdin);
        if(n == 'a' || n == 'A') {//��J���O�_�Oa
            optionA(seat);
            printf("�Ы����N���^�D���...\n");
            getch();
            system("CLS");
            continue;
        }
        if(n == 'b' || n == 'B') {//��J���O�_�Ob
            optionB(seatB);
            printf("�Ы����N���^�D���...\n");
            getch();
            system("CLS");
            continue;
        }
        if(n == 'c' || n == 'C') {//��J���O�_�Oc
            optionC(seatB);
            system("CLS");
            continue;
        }
        if(n == 'd' || n == 'D') {//��J���O�_�Od
            printf("Continue? (y/n): ");
            do {
                scanf(" %c", &ch1);
                fflush(stdin);
                if(ch1 == 'y' || ch1 == 'Y') {
                    system("CLS");
                    break;
                } else if(ch1 == 'n' || ch1 == 'N') {
                    printf("�{�������C\n");
                    return 0;
                } else {
                    printf("���~��J�A�Э��s��J(y/n): ");
                }
            } while(1);
            continue;
        } 
		else {//���Oabc
            printf("��J���~�A�Э��s��J�C\n");
            continue;
        }
    } while(1);

    return 0;
}


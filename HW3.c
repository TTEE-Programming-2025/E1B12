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
        	count++; // �u�b���\��m�@�� * �~�W�[ count
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
	int key,time=0,j,k,l,num;//�w�q�ܼơA���O�N��:�K�X/����/�j��/�j��/�j��/b����J�Ʀr 
	char n,ch1;//�w�q�ܼơA���O�O�@�}�l��J��abc/a c��J���r�� 
	char seat[9][9];

	printf("�п�J4��ƱK�X:");
	do{
		
		
		scanf("%d",&key); 
		fflush(stdin);
		if(key==2025){//�T�{�K�X�O�_���T 
			break;
		}
		if(time>1){//�ˬd��J���ơA��J���~3������ 
			printf("���~!\n");
			return 0;
		}
		else{//��J���~�ɪ����� 
			printf("�ЦA����J4��ƱK�X:");
		}
		time++;
	}while(1);
	system("CLS");
	//the menu
	do{
		printf("----[Booking System]----\n");
		printf("|a. Available seats    |\n");//�D���� 
		printf("|b. Arrange for you    |\n");
		printf("|c. Choose by yourself |\n");
		printf("|d. Exit               |\n");
		printf("------------------------\n");
		printf("Please enter a or b or c or d:");
		scanf("%c",&n);
		fflush(stdin);
		if(n=='a'||n=='A'){//��J���O�_�Oa 
			optionA(seat);
			printf("�Ы��U���N��A�^��D���\n");
			getch();
			system("CLS");
			continue;//�^��D����	
		}
		/*if(n=='b'||n=='B'){//��J���O�_�Ob
			optionB(seatB);		
		}
		if(n=='c'||n=='C'){
			optionC(seatB);
		}*/
		if(n=='d'||n=='D'){//��J���O�_�Oc
			printf("Continue?(y/n):");
			do{//�T�{��J
				scanf("%c",&ch1);
				fflush(stdin);
				switch(ch1){
					case 'y':
					case 'Y':
						system("CLS");
						break;
					case 'N':
					case 'n':
						printf("�{������");
						return 0;
					default:
						printf("���~!�A�Э���:");
						continue;
				}break;
			}while(1);
			continue;	
		}
		else{//��J�����Oa b c
			printf("���~!�Э��s��J\n");
			continue;
		}
	}while(1);

	
	return 0;
}

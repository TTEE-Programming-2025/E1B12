#include<stdio.h>
#include<stdlib.h>
int main(void){
	int i,key,time=0,j,k,l,num;
	char n,ch1;
	for(i=0;i<20;i++){
		printf("******\n");
	}
	printf("�K�X2025\n");
	printf("�п�J4��ƱK�X:");
	do{
		
		
		scanf("%d",&key);
		fflush(stdin);
		if(key==2025){
			break;
		}
		if(time>1){
			printf("���~!\n");
			return 0;
		}
		else{
			printf("�ЦA����J4��ƱK�X:");
		}
		time++;
	}while(1);
	system("CLS");
	do{
		printf("a. �e�X�����T����\nb. ��ܭ��k��\nc. ����\n");
		printf("�п�Ja��b��c:");
		scanf("%c",&n);
		fflush(stdin);
		if(n=='a'||n=='A'){
			system("CLS");
			printf("�п�Ja~n���r��:");
			do{
				scanf("%c",&ch1);
				fflush(stdin);
				if(ch1<'a'||ch1>'n'){
					printf("�Э��s��Ja~n���r��:");
					continue;
				}
				else{
					system("CLS");
					for(j=ch1;j>='a';j--){
						for(k=j;k>'a';k--){
							printf(" ");
						}
						for(l=j;l<=ch1;l++){
							printf("%c",l);
						}
						printf("\n");
					}
					printf("�Ы��U���N��A�^��D���\n");
					getch();
					system("CLS");
					break;
				}
			}while(1);
			continue;	
		}
		if(n=='b'||n=='B'){
			printf("�п�J�@�Ӿ��:");
			do{
				scanf("%d",&num);
				fflush(stdin);
				if(num<1||num>9){
					printf("���~!�ЦA����J�@�Ӿ��:");
					continue;
				}
				else{
					for(j=1;j<=num;j++){
						for(k=1;k<=num;k++){
							printf("%d * %d = %2d ",j,k,j*k);
						}
						printf("\n");
					}
					printf("�Ы��U���N��A�^��D���\n");
					getch();
					system("CLS");
					break;
				}
			}while(1);
			continue;		
		}
		if(n=='c'||n=='C'){
			printf("Continue?(y/n):");
			do{
				scanf("%c",&ch1);
				fflush(stdin);
				switch(ch1){
					case 'y':
					case 'Y':
						system("CLS");
						break;
					case 'N':
					case 'n':
						return 0;
					default:
						printf("���~!�A�Э���:");
						continue;
				}break;
			}while(1);
			continue;	
		}
		else{
			printf("���~!�Э��s��J\n");
			continue;
		}
	}while(1);

	
	return 0;
} 

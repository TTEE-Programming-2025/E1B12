#include<stdio.h>
#include<stdlib.h>
int main(void){
	int i,key,time=0,j,k,l,num;
	char n,ch1;
	for(i=0;i<20;i++){
		printf("******\n");
	}
	printf("密碼2025\n");
	printf("請輸入4位數密碼:");
	do{
		
		
		scanf("%d",&key);
		fflush(stdin);
		if(key==2025){
			break;
		}
		if(time>1){
			printf("錯誤!\n");
			return 0;
		}
		else{
			printf("請再次輸入4位數密碼:");
		}
		time++;
	}while(1);
	system("CLS");
	do{
		printf("a. 畫出直角三角形\nb. 顯示乘法表\nc. 結束\n");
		printf("請輸入a或b或c:");
		scanf("%c",&n);
		fflush(stdin);
		if(n=='a'||n=='A'){
			system("CLS");
			printf("請輸入a~n的字元:");
			do{
				scanf("%c",&ch1);
				fflush(stdin);
				if(ch1<'a'||ch1>'n'){
					printf("請重新輸入a~n的字元:");
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
					printf("請按下任意鍵，回到主選單\n");
					getch();
					system("CLS");
					break;
				}
			}while(1);
			continue;	
		}
		if(n=='b'||n=='B'){
			printf("請輸入一個整數:");
			do{
				scanf("%d",&num);
				fflush(stdin);
				if(num<1||num>9){
					printf("錯誤!請再次輸入一個整數:");
					continue;
				}
				else{
					for(j=1;j<=num;j++){
						for(k=1;k<=num;k++){
							printf("%d * %d = %2d ",j,k,j*k);
						}
						printf("\n");
					}
					printf("請按下任意鍵，回到主選單\n");
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
						printf("錯誤!，請重輸:");
						continue;
				}break;
			}while(1);
			continue;	
		}
		else{
			printf("錯誤!請重新輸入\n");
			continue;
		}
	}while(1);

	
	return 0;
} 

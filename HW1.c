#include<stdio.h>
#include<stdlib.h>
int main(void){
	int i,key,c;
	char ch;
	for(i=0;i<20;i++){
		printf("!@#$%^&*()@^@\n");
	}
	system("pause");
	system("CLS");
	printf("��J�K�X:");
	scanf("%d",&key);
	if(key==2025){
	printf("�K�X���T\n");
	printf("�w��~~~~~\n");
	system("pause");
	system("CLS");
	printf("*********************\n");
	printf("*'A'---'Z':Uppercase*\n");
	printf("*'a'---'z':Lowercase*\n");
	printf("*'0'---'9':Digit    *\n");
	printf("*Otherwise:your name*\n");
	printf("*********************\n");
	printf("�п�J�@�r��:");
	fflush(stdin);
	scanf("%c",&ch);
	if((ch>='A')&&(ch<='Z'))
	printf("Uppercase\n");
	else if((ch>='a')&&(ch<='z'))
	printf("Lowercase\n");
	else if((ch>='0')&&(ch<='9'))
	printf("Digit\n");
	else
	printf("E1B12�୳�Q\n");
	}
	else{
		printf("�K�X���~");
		
	}
	
	
	
	system("pause");
	return 0;
}

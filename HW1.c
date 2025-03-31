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
	printf("¿é¤J±K½X:");
	scanf("%d",&key);
	if(key==2025){
	printf("±K½X¥¿½T\n");
	printf("Åwªï~~~~~\n");
	system("pause");
	system("CLS");
	printf("*********************\n");
	printf("*'A'---'Z':Uppercase*\n");
	printf("*'a'---'z':Lowercase*\n");
	printf("*'0'---'9':Digit    *\n");
	printf("*Otherwise:your name*\n");
	printf("*********************\n");
	printf("½Ð¿é¤J¤@¦r¤¸:");
	fflush(stdin);
	scanf("%c",&ch);
	if((ch>='A')&&(ch<='Z'))
	printf("Uppercase\n");
	else if((ch>='a')&&(ch<='z'))
	printf("Lowercase\n");
	else if((ch>='0')&&(ch<='9'))
	printf("Digit\n");
	else
	printf("E1B12¿à­³¿Q\n");
	}
	else{
		printf("±K½X¿ù»~");
		
	}
	
	
	
	system("pause");
	return 0;
}

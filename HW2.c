#include<stdio.h>
#include<stdlib.h>
int main(void){
	int key,time=0,j,k,l,num;//�w�q�ܼơA���O�N��:�K�X/����/�j��/�j��/�j��/b����J�Ʀr 
	char n,ch1;//�w�q�ܼơA���O�O�@�}�l��J��abc/a c��J���r�� 
	printf("                    ******  ******  ******  ******\n");
	printf("                         *  *    *       *  *     \n");
	printf("                         *  *    *       *  *     \n");
	printf("                         *  *    *       *  *     \n");
	printf("     *     *        ******  *    *  ******  ******        *     *    \n");
	printf("    * *   * *       *       *    *  *            *       * *   * *   \n");
	printf("    * *   * *       *       *    *  *            *       * *   * *   \n");
	printf("*    * *   * *     **       *    *  *            **     * *   * *   *\n");
	printf("* *   * *   * *   * ******  ******  ******  ****** *   * *   * *   * *\n");
	printf("    *  *  *  * *   *  *  *                  *  *  *   * *  *  *  *    \n");
	printf("     *  *  *  * *   *  *  * *            * *  *  *   * *  *  *  *     \n");
	printf("     *  *  *  * *   *  *  * *            * *  *  *   * *  *  *  *     \n");
	printf("     *  *  *  * *   *  *  * *            * *  *  *   * *  *  *  *     \n");
	printf("     *  *  *  * *   *  *  * *            * *  *  *   * *  *  *  *     \n");
	printf("     *  *  *  * *   *  *  * *            * *  *  *   * *  *  *  *     \n");
	printf("     *  *  *  * *   *  *  * *            * *  *  *   * *  *  *  *     \n");
	printf("     *  *  *  * *   *  *  * *            * *  *  *   * *  *  *  *     \n");
	printf("     *  *  *  * *   *  *  * *     **     * *  *  *   * *  *  *  *     \n");
	printf("     *  *  *  * *   *  *  * *    *  *    * *  *  *   * *  *  *  *     \n");
	printf("     *  *  *  * *   *  *  * *   *    *   * *  *  *   * *  *  *  *     \n");
	printf("�K�X2025\n");
	printf("�п�J4��ƱK�X:");
	do{
		
		
		scanf("%d",&key);
		fflush(stdin);
		if(key==2025){//�T�{�K�X�O�_���T 
			break;
		}
		if(time>1){//�ˬd��J���� 
			printf("���~!\n");
			return 0;
		}
		else{//��J���~�ɪ����� 
			printf("�ЦA����J4��ƱK�X:");
		}
		time++;
	}while(1);
	system("CLS");
	do{
		printf("a. �e�X�����T����\nb. ��ܭ��k��\nc. ����\n");//�D���� 
		printf("�п�Ja��b��c:");
		scanf("%c",&n);
		fflush(stdin);
		if(n=='a'||n=='A'){//��J���O�_�Oa 
			system("CLS");
			printf("�п�Ja~n���r��:");
			do{
				scanf("%c",&ch1);
				fflush(stdin);
				if(ch1<'a'||ch1>'n'){//���Oa~n�n�D���� 
					printf("�Э��s��Ja~n���r��:");
					continue;
				}
				else{
					system("CLS");
					for(j=ch1;j>='a';j--){//�L�X�T���� 
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
			continue;//�^��D����	
		}
		if(n=='b'||n=='B'){//��J���O�_�Ob
			printf("�п�J�@�Ӿ��:");
			do{
				scanf("%d",&num);
				fflush(stdin);
				if(num<1||num>9){//���O1~9�n�D���� 
					printf("���~!�ЦA����J�@�Ӿ��:");
					continue;
				}
				else{//�L�X���k�� 
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
		if(n=='c'||n=='C'){//��J���O�_�Oc
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
/*�o�����@�~���ڧ�`�J�F�Ѱj��Mcontinue�y�y�����ΡC
�z�L��ڽs�g�{���A�ھǷ|�F�p��ϥΰj��Ӥ��а���S�w
���ȡA�P�ɹB��continue�Ӧ^��D�e���A�F���@�~�n�D�C�o
���ȼW�j�F�ڪ��޿����A�]���ڦb�g�{���ɧ�[�o������
�A���ɤF�ѨM���D����O�C*/ 

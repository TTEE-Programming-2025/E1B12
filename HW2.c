#include<stdio.h>
#include<stdlib.h>
int main(void){
	int key,time=0,j,k,l,num;//定義變數，分別代表:密碼/次數/迴圈/迴圈/迴圈/b的輸入數字 
	char n,ch1;//定義變數，分別是一開始輸入的abc/a c輸入的字元 
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
	printf("密碼2025\n");
	printf("請輸入4位數密碼:");
	do{
		
		
		scanf("%d",&key);
		fflush(stdin);
		if(key==2025){//確認密碼是否正確 
			break;
		}
		if(time>1){//檢查輸入次數 
			printf("錯誤!\n");
			return 0;
		}
		else{//輸入錯誤時的提醒 
			printf("請再次輸入4位數密碼:");
		}
		time++;
	}while(1);
	system("CLS");
	do{
		printf("a. 畫出直角三角形\nb. 顯示乘法表\nc. 結束\n");//主介面 
		printf("請輸入a或b或c:");
		scanf("%c",&n);
		fflush(stdin);
		if(n=='a'||n=='A'){//輸入的是否是a 
			system("CLS");
			printf("請輸入a~n的字元:");
			do{
				scanf("%c",&ch1);
				fflush(stdin);
				if(ch1<'a'||ch1>'n'){//不是a~n要求重輸 
					printf("請重新輸入a~n的字元:");
					continue;
				}
				else{
					system("CLS");
					for(j=ch1;j>='a';j--){//印出三角形 
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
			continue;//回到主介面	
		}
		if(n=='b'||n=='B'){//輸入的是否是b
			printf("請輸入一個整數:");
			do{
				scanf("%d",&num);
				fflush(stdin);
				if(num<1||num>9){//不是1~9要求重輸 
					printf("錯誤!請再次輸入一個整數:");
					continue;
				}
				else{//印出乘法表 
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
		if(n=='c'||n=='C'){//輸入的是否是c
			printf("Continue?(y/n):");
			do{//確認輸入
				scanf("%c",&ch1);
				fflush(stdin);
				switch(ch1){
					case 'y':
					case 'Y':
						system("CLS");
						break;
					case 'N':
					case 'n':
						printf("程式結束");
						return 0;
					default:
						printf("錯誤!，請重輸:");
						continue;
				}break;
			}while(1);
			continue;	
		}
		else{//輸入的不是a b c
			printf("錯誤!請重新輸入\n");
			continue;
		}
	}while(1);

	
	return 0;
}
/*這次的作業讓我更深入了解迴圈和continue語句的應用。
透過實際編寫程式，我學會了如何使用迴圈來反覆執行特定
任務，同時運用continue來回到主畫面，達成作業要求。這
不僅增強了我的邏輯思維，也讓我在寫程式時更加得心應手
，提升了解決問題的能力。*/ 

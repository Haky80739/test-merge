#include <stdio.h>
#include <stdlib.h>

typedef struct  _bill
{
	int mode1;
	char title[10];
	int price;
	int month;
	int day;
	int pocketbalance;
	int bankbalance;
	int receipt;
} bill;

bill data[101];

void print(int p);
void pname();
void pn(int n);
void calculate1(int c);
void calculate2(int c);
void calculate3(int c);
void calculate4(int c);
void calculate5(int c);
void calculate6(int c);
void fp(int f);
void inp(int l,int m);
void look(int l);
void sum(int m,int l);
FILE* pFile;
rece[8]={0};


int main() {

	
	int mode;
	int i,j;
	int mode1;
	int last = 1;
	int confirm=0;
	int mon;
	

	pFile = fopen("d://money.txt", "a+");
	

	while (1)
	{
		while (1)
		{
			printf("\n\n\n請輸入模式(記帳:1/查詢明細:2/輸入發票中獎號碼:3/統計:4/退出程式:0):");
			scanf_s("%d", &mode);
			if (mode > 0 || mode < 5) break;
		}

		/////////////////////////////////////////////////////////////////

		if (NULL == pFile) {
			printf("open failure");
		}
		else {
			last = 1;
			for (i = 1; i <= 101; i++)
			{
				fscanf(pFile, "\n%d", &data[i].mode1);
				if (data[i].mode1 <= 0 || data[i].mode1 >= 7)
				{
					last -= 1;
					break;
				}
				fscanf(pFile, "%s", data[i].title);
				fscanf(pFile, "%d", &data[i].price);
				fscanf(pFile, "%d", &data[i].month);
				fscanf(pFile, "%d", &data[i].day);
				fscanf(pFile, "%d", &data[i].pocketbalance);
				fscanf(pFile, "%d", &data[i].bankbalance);
				fscanf(pFile, "%d", &data[i].receipt);
				last += 1;
			}
			if(last == 0)
			{
				data[0].mode1=0;
				data[0].price=0;
				printf("請輸入錢包起始金額:");
				scanf("%d",&data[0].pocketbalance);
				printf("請輸入銀行存款起始金額:");
				scanf("%d",&data[0].bankbalance);
				data[0].receipt=0;
			}
         


			///////////////////////////////////////////////////////////////////
			switch (mode)
			{
			case 0:
				system("pause");
				return 0;
				break;

				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 1:
				printf("\n記帳:");
				while (1)
				{
					printf("\n請輸入類別(支出:1/收入:2/存入帳戶:3/帳戶領出:4/匯入帳戶:5/匯出帳戶:6):");
					scanf("%d", &mode1);
					if (mode1 > 0 || mode1 < 6) break;
				}
				switch (mode1)
				{
				case 1:
					confirm = 0;
					while (confirm != 1)
					{
						printf("請輸入名稱(10字內):");
						scanf_s("%s", &data[last + 1].title);
						printf("請輸入金額:");
						scanf_s("%d", &data[last + 1].price);
						printf("請輸入月份:");
						scanf_s("%d", &data[last + 1].month);
						printf("請輸入日期:");
						scanf_s("%d", &data[last + 1].day);
						printf("請輸入發票號碼(8碼):");
						scanf_s("%d", &data[last + 1].receipt);
						printf("\n確認");
						pn(mode1);
						printf("\n名稱:");
						printf("%-10s", data[last + 1].title);
						printf("\n金額:%d\n", data[last + 1].price);
						printf("日期:%d/%d\n", data[last + 1].month ,data[last + 1].day);
						printf("發票號碼:%d\n", data[last + 1].receipt);
						printf("\n確認請按1，重新輸入請按0:");
						scanf("%d", &confirm);
					}
					calculate1(last);
					printf("OK!! \n");
					pname();
					print(last + 1);
					fp(last + 1);
					break;
				case 2:
				    inp(last,mode1);
					calculate2(last);
					printf("OK!! \n");
					pname();
					print(last + 1);
					fp(last + 1);
					
					break;
				case 3:
					inp(last,mode1);
					calculate3(last);
					printf("OK!!\n");
					pname();
					print(last + 1);
					fp(last + 1);
					
					break;
				case 4:
					inp(last,mode1);
					calculate4(last);
					printf("OK!!\n");
					pname();
					print(last + 1);
					fp(last + 1);
					break;
				case 5:
					inp(last,mode1);
					calculate5(last);
					printf("OK!!\n");
					pname();
					print(last + 1);
					fp(last + 1);
					break;
				case 6:
					inp(last,mode1);
					calculate6(last);
					printf("OK!!\n");
					pname();
					print(last + 1);
					fp(last + 1);
					break;
				}


				last += 1;
				break;


				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 2:
				printf("\n查詢明細:\n\n");
				pname();
				for (i = 1; i <= last; i++)
				{
					print(i);
				}
				break;


				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 3:
				if(rece[0]==0)
				{
					printf("\n請輸入發票中獎號碼:\n");
					printf("特別獎(8碼):");
					scanf("%d",&rece[0]);
					printf("特獎(8碼):");
					scanf("%d",&rece[1]);
					printf("頭獎(8碼):");
					scanf("%d",&rece[2]);
					printf("頭獎(8碼):");
					scanf("%d",&rece[3]);
                	printf("頭獎(8碼):");
					scanf("%d",&rece[4]);
             	    printf("增開六獎(3碼):");
					scanf("%d",&rece[5]);
             	    printf("增開六獎(3碼):");
					scanf("%d",&rece[6]);
					printf("增開六獎(3碼):");
					scanf("%d",&rece[7]);
					printf("\n\n\n");
           		}
           		look(last);
				break;
				
			case 4:
				printf("\n統計:\n\n");
				printf("請輸入月份:");
				scanf_s("%d",&mon);
				sum(mon,last);
				break;
				 
			}

		}
		fclose(pFile);
	}
}
void pname()
{
	printf("種類\t\t名稱\t\t金額\t月份\t日期\t錢包餘額\t帳戶餘額\t發票號碼\n");
}

void inp(int l,int m)
{
	int j;
	int confirm = 0;
	while (confirm != 1)
	{
		printf("請輸入名稱(10字內):");
		scanf_s("%s", &data[l + 1].title);
		printf("請輸入金額:");
		scanf_s("%d", &data[l + 1].price);
		printf("請輸入月份:");
		scanf_s("%d", &data[l + 1].month);
		printf("請輸入日期:");
		scanf_s("%d", &data[l + 1].day);
		printf("\n確認");
		pn(m);
		printf("\n名稱:");
		printf("%-10s", data[l + 1].title);
		printf("\n金額:%d\n", data[l + 1].price);
		printf("日期:%d/%d\n", data[l + 1].month ,data[l + 1].day);
		printf("\n確認請按1，重新輸入請按0:");
		scanf("%d", &confirm);
	}
	
}

void pn(int n)
{
	switch(n)
	{
		case 0:
		    printf("起始\t\t");
			break;
		case 1:
			printf("支出\t\t");
			break;
		case 2:
			printf("收入\t\t");
			break;
		case 3:
			printf("存入帳戶\t");
			break;
		case 4:
			printf("帳戶領出\t");
			break;
		case 5:
			printf("匯入帳戶\t");
			break;
		case 6:
			printf("匯出帳戶\t");
			break;
	}
}

void print(int p)
{
	int r;
	pn(data[p].mode1);
	printf("%-10s", data[p].title);
	printf("\t");
	printf("%d\t", data[p].price);
	printf("%d\t", data[p].month);
	printf("%d\t", data[p].day);
	printf("%d\t\t", data[p].pocketbalance);
	printf("%d\t\t", data[p].bankbalance);
	printf("%d\n", data[p].receipt);
}

void calculate1(int c)
{
	data[c + 1].mode1 = 1;
	data[c + 1].pocketbalance = data[c].pocketbalance - data[c+1].price;
	data[c + 1].bankbalance = data[c].bankbalance;
}

void calculate2(int c)
{
	data[c + 1].receipt=0;
	data[c + 1].mode1 = 2;
	data[c + 1].pocketbalance = data[c].pocketbalance + data[c+1].price;
	data[c + 1].bankbalance = data[c].bankbalance;
}

void calculate3(int c)
{
	data[c + 1].receipt=0;
	data[c + 1].mode1 = 3;
	data[c + 1].pocketbalance = data[c].pocketbalance - data[c+1].price;
	data[c + 1].bankbalance = data[c].bankbalance + data[c+1].price;
}

void calculate4(int c)
{
	data[c + 1].receipt=0;
	data[c + 1].mode1 = 4;
	data[c + 1].pocketbalance = data[c].pocketbalance + data[c+1].price;
	data[c + 1].bankbalance = data[c].bankbalance - data[c+1].price;
}

void calculate5(int c)
{
	data[c + 1].receipt=0;
	data[c + 1].mode1 = 5;
	data[c + 1].pocketbalance = data[c].pocketbalance;
	data[c + 1].bankbalance = data[c].bankbalance + data[c+1].price;
}

void calculate6(int c)
{
	data[c + 1].receipt=0;
	data[c + 1].mode1 = 6;
	data[c + 1].pocketbalance = data[c].pocketbalance;
	data[c + 1].bankbalance = data[c].bankbalance - data[c+1].price;
}

void fp(int f)
{
	int r;
	fprintf(pFile, "%d ", data[f].mode1);
	fprintf(pFile, "%-10s", data[f].title);
	fprintf(pFile, " ");
	fprintf(pFile, "%d ", data[f].price);
	fprintf(pFile, "%d ", data[f].month);
	fprintf(pFile, "%d ", data[f].day);
	fprintf(pFile, "%d ", data[f].pocketbalance);
	fprintf(pFile, "%d ", data[f].bankbalance);
	fprintf(pFile, "%d\n", data[f].receipt);
}

void sum(int m,int l)
{
	int total1=0;
	int total2=0;
	int i,j;
	int a=0;
	for(j=1;j<=l;j++)
	{
		if(data[j].month==m && (data[j].mode1==1 || data[j].mode1==6))
		{
			total+=data[j].price;
			a++;
		} 
	}
	printf("\n%d月總共花了:%d元\n",m,total1);
	printf("平均一天花了:%d元\n\n",total1/a);
	for(j=1;j<=l;j++)
	{
		if(data[j].month==m && (data[j].mode1==2 || data[j].mode1==5))
		{
			total+=data[j].price;
			a++;
		} 
	}
	printf("%d月收入:%d元\n",m,total2);
	
}

void look(int l)
{
	int i,j;
	for (i=1;i<=l;i++)
	{
		if(data[i].receipt==rece[0])
		{
			printf("恭喜您中1000萬!! ");
			printf("發票號碼:%d\n",data[i].receipt);
		}
		if(data[i].receipt==rece[1])
		{
			printf("恭喜您中200萬!! ");
			printf("發票號碼:%d\n",data[i].receipt);
		}
		for(j=2;j<=4;j++)
		{
			if(data[i].receipt==rece[j])
			{
				printf("恭喜您中20萬!! ");
				printf("發票號碼:%d\n",data[i].receipt);
			}
			else if(data[i].receipt%10000000==rece[j]%10000000)
			{
				printf("恭喜您中4萬!! ");
				printf("發票號碼:%d\n",data[i].receipt);
			}
			else if(data[i].receipt%1000000==rece[j]%1000000)
			{
				printf("恭喜您中1萬!! ");
				printf("發票號碼:%d\n",data[i].receipt);
			}
			else if(data[i].receipt%100000==rece[j]%100000)
				{
				printf("恭喜您中4千!! ");
				printf("發票號碼:%d\n",data[i].receipt);
			}
			else if(data[i].receipt%10000==rece[j]%10000)
			{
				printf("恭喜您中1千!! ");
				printf("發票號碼:%d\n",data[i].receipt);
			}
			else if(data[i].receipt%1000==rece[j]%1000)
			{
				printf("恭喜您中2百!! ");
				printf("發票號碼:%d\n",data[i].receipt);
			}
		}
		for(j=5;j<=7;j++)
		{
			if(data[i].receipt%1000==rece[j])
			{
				printf("恭喜您中2百!! ");
				printf("發票號碼:%d\n",data[i].receipt);
			}
		}
	}
}


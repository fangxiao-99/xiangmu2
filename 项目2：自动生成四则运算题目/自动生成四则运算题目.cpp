#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int chachong[10000][2]={(0,0)}; //查重的数组， 储存答案，答案相同则视为相同题目 
int ysf=0;  //题目中的运算符个数 
char sig[3];  //存储运算符的数组 
char getSignal() //获得运算符的函数 
{
    char signal[4]={'+','-','*','/'};
    return signal[rand()%4];
}

typedef struct fen{		//分数结构体声明
      int q=0;
	int fenzi=0;
	int fenmu=1;
}fenshu;

fenshu a1,a2,a3,a4,a5;

void yuefen(int &m, int &n) //约分
{
	int p;
	p = (m + n - abs(m - n)) / 2;//p为m，n中较小值
	for (int i = 2; i <= p; i++)
		if (m%i == 0 && n%i == 0)
		{
			m /= i;
			n /= i;
			i = 2;
		}
}

fenshu shengcheng(int r) //生成范围在r内的题目 
{
        ysf= rand() %3 + 1;          //首先明确这条题目有多少运算符 
		a1.fenmu = rand() %r + 1;
		a2.fenmu = rand() %r + 1;
		a3.fenmu = rand() %r + 1;
		a4.fenmu = rand() %r + 1;
		a1.fenzi =rand()%(a1.fenmu*a1.fenmu)+1;
		a2.fenzi =rand()%(a2.fenmu*a2.fenmu)+1;
		a3.fenzi =rand()%(a3.fenmu*a3.fenmu)+1;
		a4.fenzi =rand()%(a3.fenmu*a3.fenmu)+1;
		yuefen(a1.fenzi, a1.fenmu);
		yuefen(a2.fenzi, a2.fenmu);
		yuefen(a3.fenzi, a3.fenmu);
		yuefen(a4.fenzi, a4.fenmu);
        sig[0]=getSignal();
         sig[1]=getSignal();
         sig[2]=getSignal();
	
}
fenshu jia(fenshu a1, fenshu a2) {			//加法
	fenshu a9;
	int f, g;
	f = a1.fenzi * a2.fenmu + a1.fenmu * a2.fenzi;
	g = a1.fenmu * a2.fenmu;
	yuefen(f, g);
	a9.fenzi = f;
	a9.fenmu = g;
	return a9;
}

fenshu jian(fenshu a1, fenshu a2) {	//减法
	fenshu a9;
	int f, g;
	f = a1.fenzi * a2.fenmu - a1.fenmu * a2.fenzi;
	g = a1.fenmu * a2.fenmu;
	yuefen(f, g);
	a9.fenzi = f;
	a9.fenmu = g;
	return a9;
}

fenshu chu(fenshu a1, fenshu a2) {	//除法
	fenshu a9;
	int f, g;
	f = a1.fenzi * a2.fenmu;
	g = a1.fenmu * a2.fenzi;
	yuefen(f, g);
	a9.fenzi = f;
	a9.fenmu = g;
	return a9;
}

fenshu cheng(fenshu a1, fenshu a2) {	//乘法
	fenshu a9;
	int f, g;
	f = a1.fenzi * a2.fenzi;
	g = a1.fenmu * a2.fenmu;
	yuefen(f, g);
	a9.fenzi = f;
	a9.fenmu = g;
	return a9; 
}
void shuchu(char a, char b, char c, fenshu a1, fenshu a2, fenshu a3, fenshu a4, fenshu a5, int number, int max, FILE *fp, FILE *bp)
{                                                                                             //根据ysf的值用switch函数输出 
     switch(ysf)
  {  case 1:
		if (a5.fenzi < a5.fenmu)
		{
            fprintf(fp, "%d.四则运算题目%d'%d/%d %c %d'%d/%d = %d/%d\n", number,a1.fenzi/a1.fenmu,a1.fenzi%a1.fenmu,a1.fenmu,a,a2.fenzi/a2.fenmu,a2.fenzi%a2.fenmu,a2.fenmu,a5.fenzi,a5.fenmu);
			fprintf(bp, "%d.答案=%d/%d\n", number, a5.fenzi, a5.fenmu); break;
		}
		else
			if (a5.fenmu == 1)
			{
				fprintf(fp,"%d.四则运算题目%d'%d/%d %c %d'%d/%d = %d\n",number,a1.fenzi/a1.fenmu,a1.fenzi%a1.fenmu,a1.fenmu,a,a2.fenzi/a2.fenmu,a2.fenzi%a2.fenmu,a2.fenmu, a5.fenzi);
				fprintf(bp, "%d.答案=%d\n", number, a5.fenzi); break;
			}
			else
			{
				fprintf(fp, "%d.四则运算题目%d'%d/%d %c %d'%d/%d = %d'%d/%d\n", number,a1.fenzi/a1.fenmu,a1.fenzi%a1.fenmu,a1.fenmu,a,a2.fenzi/a2.fenmu,a2.fenzi%a2.fenmu,a2.fenmu,a5.fenzi/a5.fenmu,a5.fenzi%a5.fenmu,a5.fenmu);
				fprintf(bp, "%d.答案=%d'%d/%d\n", number, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu); break;
			}
			break;
	  case 2:
	    	if (a5.fenzi < a5.fenmu)
	{
		fprintf(fp, "%d .四则运算题目%d'%d/%d %c %d'%d/%d %c %d'%d/%d = %d/%d\n", number,a1.fenzi/a1.fenmu,a1.fenzi%a1.fenmu,a1.fenmu, a,a2.fenzi/a2.fenmu,a2.fenzi%a2.fenmu,a2.fenmu, b,a3.fenzi/a3.fenmu,a3.fenzi%a3.fenmu, a3.fenmu, a5.fenzi, a5.fenmu);
		fprintf(bp, "%d .答案=%d/%d\n", number, a5.fenzi, a5.fenmu);
	}
	else
		if (a5.fenmu == 1)
		{
	    	fprintf(fp, "%d .四则运算题目%d'%d/%d %c %d'%d/%d %c %d'%d/%d = %d\n", number,a1.fenzi/a1.fenmu,a1.fenzi%a1.fenmu,a1.fenmu, a,a2.fenzi/a2.fenmu,a2.fenzi%a2.fenmu,a2.fenmu, b,a3.fenzi/a3.fenmu,a3.fenzi%a3.fenmu, a3.fenmu, a5.fenzi);
			fprintf(bp, "%d.答案=%d\n", number, a5.fenzi);
		}
		else
		{
            fprintf(fp, "%d .四则运算题目%d'%d/%d %c %d'%d/%d %c %d'%d/%d = %d'%d/%d\n", number,a1.fenzi/a1.fenmu,a1.fenzi%a1.fenmu,a1.fenmu, a,a2.fenzi/a2.fenmu,a2.fenzi%a2.fenmu,a2.fenmu, b,a3.fenzi/a3.fenmu,a3.fenzi%a3.fenmu, a3.fenmu, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu);
			fprintf(bp, "%d.答案=%d'%d/%d\n", number, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu);
		}
		break;	
      case 3:
    	if (a5.fenzi < a5.fenmu)
    	{
		fprintf(fp, "%d .四则运算题目%d'%d/%d %c %d'%d/%d %c %d'%d/%d %c %d'%d/%d = %d/%d\n", number,a1.fenzi/a1.fenmu,a1.fenzi%a1.fenmu, a1.fenmu, a,a2.fenzi/a2.fenmu,a2.fenzi%a2.fenmu, a2.fenmu, b,a3.fenzi/a3.fenmu,a3.fenzi%a3.fenmu, a3.fenmu, c,a4.fenzi/a4.fenmu,a4.fenzi%a4.fenmu, a4.fenmu, a5.fenzi, a5.fenmu);
		fprintf(bp, "%d .答案=%d/%d\n", number, a5.fenzi, a5.fenmu);
    	}
    	else
	    	if (a5.fenmu == 1)
		{
		fprintf(fp, "%d .四则运算题目%d'%d/%d %c %d'%d/%d% c% d'%d/%d %c %d'%d/%d=%d\n", number,a1.fenzi/a1.fenmu,a1.fenzi%a1.fenmu, a1.fenmu, a,a2.fenzi/a2.fenmu,a2.fenzi%a2.fenmu, a2.fenmu, b,a3.fenzi/a3.fenmu,a3.fenzi%a3.fenmu, a3.fenmu, c,a4.fenzi/a4.fenmu,a4.fenzi%a4.fenmu, a4.fenmu, a5.fenzi);
			fprintf(bp, "%d.答案=%d\n", number, a5.fenzi);
		}
	    	else
		{
		fprintf(fp, "%d .四则运算题目%d'%d/%d %c %d'%d/%d %c %d'%d/%d %c %d'%d/%d = %d'%d/%d\n", number,a1.fenzi/a1.fenmu,a1.fenzi%a1.fenmu, a1.fenmu, a,a2.fenzi/a2.fenmu,a2.fenzi%a2.fenmu, a2.fenmu, b,a3.fenzi/a3.fenmu,a3.fenzi%a3.fenmu, a3.fenmu, c,a4.fenzi/a4.fenmu,a4.fenzi%a4.fenmu, a4.fenmu, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu);
			fprintf(bp, "%d.答案=%d'%d/%d\n", number, a5.fenzi / a5.fenmu, a5.fenzi%a5.fenmu, a5.fenmu);
		}
		break;
	default: 
	printf("输入文件失败");
	break; 
  } 
}
fenshu jisuan(char a, fenshu a1, fenshu a2, fenshu a5) {
	switch (a)
	{
	case '+':   //加法
		a5 = jia(a1,a2);
		yuefen(a5.fenzi, a5.fenmu);
        break;
	case '-': a5 = jian(a1, a2);  //减法
		yuefen(a5.fenzi, a5.fenmu);
        break;
	case '*': a5 = cheng(a1, a2); //乘法
		yuefen(a5.fenzi, a5.fenmu);
		break;

	case '/': a5 = chu(a1, a2); //除法
		yuefen(a5.fenzi, a5.fenmu);
        break;
	}
	return a5;
}

fenshu jisuan2(char a, char b, fenshu a1, fenshu a2, fenshu a3, fenshu a5, fenshu a6)
{
	if (a== '*' || a == '/')
	{
		if (a == '*')
		{
			a6 = cheng(a1, a2);
			yuefen(a6.fenzi, a6.fenmu);

		}
		else
		{
			a6 = chu(a1, a2);
			yuefen(a6.fenzi, a6.fenmu);
		}
		if (b == '*')
		{
			a5 = cheng(a6, a3);
			yuefen(a5.fenzi, a5.fenmu);

		}
		else if (b == '/')
		{
			a5 = chu(a6, a3);
			yuefen(a5.fenzi, a5.fenmu);

		}
		else if (b == '+')
		{
			a5 = jia(a6, a3);
			yuefen(a5.fenzi, a5.fenmu);

		}
		else
		{
			a5 = jian(a6, a3);
			yuefen(a5.fenzi, a5.fenmu);


		}

	}
	else
	{
		if (b== '*')
		{
			a6 = cheng(a2, a3);
			yuefen(a6.fenzi, a6.fenmu);
			if (a == '+')
			{
				a5 = jia(a1, a6);
				yuefen(a5.fenzi, a5.fenmu);

			}
			else
			{
				a5 = jian(a1, a6);
				yuefen(a5.fenzi, a5.fenmu);

			}
		}
		else if (b== '/')
		{
			a6 = chu(a2, a3);
			yuefen(a6.fenzi, a6.fenmu);
			if (a == '+')
			{
				a5 = jia(a1, a6);
				yuefen(a5.fenzi, a5.fenmu);

			}
			else
			{
				a5 = jian(a1, a6);
				yuefen(a5.fenzi, a5.fenmu);

			}
		}
		else if (b == '+'||b=='-')
		{
			if (a == '+')
			{
				a6 = jia(a1, a2);
				yuefen(a6.fenzi, a6.fenmu);
				if (b == '+')
				{
					a5 = jia(a6, a3);
					yuefen(a5.fenzi, a5.fenmu);

				}
				else
				{
					a5 = jian(a6, a3);
					yuefen(a5.fenzi, a5.fenmu);

				}
			}
			else
			{
				a6 = jian(a1, a2);
				yuefen(a6.fenzi, a6.fenmu);
				if (a == '+')
				{
					a5 = jia(a6, a3);
					yuefen(a5.fenzi, a5.fenmu);

				}
				else
				{
					a5 = jian(a6, a3);
					yuefen(a5.fenzi, a5.fenmu);

				}
			}
		}
		
	}
	return a5;
}

fenshu jisuan3(char a, char b, char c, fenshu a1, fenshu a2, fenshu a3, fenshu a4, fenshu a5)
{
	fenshu a6, a7;
	if (a== '/' || a == '*') {
		if (a == '*')
		{
			a6 = cheng(a1, a2);
			yuefen(a6.fenzi, a6.fenmu);
		}
		else
		{
			a6 = chu(a1, a2);
			yuefen(a6.fenzi, a6.fenmu);
		}
			
		a5 = jisuan2(b, c, a6, a3, a4, a5, a7);
	}
	else if (b == '/' || b == '*')
	{
		if (b == '*')
		{ 
			a6 = cheng(a2, a3);
			yuefen(a6.fenzi, a6.fenmu);
		}
			
		else
		{
			a6 = chu(a2, a3);
			yuefen(a6.fenzi, a6.fenmu);
		}
		a5 = jisuan2(a, c, a1, a6, a4, a5, a7);
			
	}
	else if (c == '/' || c == '*')
	{
		if (c == '*')
		{
			a6 = cheng(a3, a4);
			yuefen(a6.fenzi, a6.fenmu);
		}

		else
		{
			a6 = chu(a3, a4);
			yuefen(a6.fenzi, a6.fenmu);
		}
		a5 = jisuan2(a, b, a1, a2, a6, a5, a7);
	}
	else
	{
		if (a == '+')
		{
			a6 = jia( a1, a2);
			yuefen(a6.fenzi, a6.fenmu);
		}
		else 
		{
			a6 = jian(a1, a2);
			yuefen(a6.fenzi, a6.fenmu);
		}
		a5 = jisuan2(a, b, a6, a3, a4, a5, a7);
	}
	return a5;
}



int main()
{
	int n, r,a=0;  
	int flag=0;  
	printf("请输入您要生成的题目的数量-n x\n");
	scanf("%d", &n);
	getchar();
	printf("请输入随机数的范围 x\n");
	scanf("%d", &r);
	getchar();
	FILE *fp;
	if ((fp = fopen("exercises1.txt", "w")) == NULL)
	{
		printf("打不开exercises1.txt!\n");
		exit(0);
	}
	FILE *bp;
	if ((bp = fopen("answers1.txt", "w")) == NULL)
	{
		printf("打不开answers1.txt!\n");
		exit(0);
	}
	int i = 0, number = 1;
	while (i < n)
	{
		fenshu a6;
        shengcheng(r);
		if (ysf == 1)
		{
			a5=jisuan(sig[0], a1, a2, a5);
			if (a5.fenzi < 0)
				continue;
				while (a<number)
				{
					if(chachong[a][0]==a5.fenzi&&chachong[a][1]==a5.fenmu)
					{
						a++;
						flag=1;
						break;
					}
					chachong[a][0]=a5.fenzi;
					chachong[a][1]=a5.fenmu;
					a++;
					flag=0;	
				}
				if(flag==1)
				continue;
					
			shuchu(sig[0], sig[1], sig[2], a1, a2, a3, a4, a5, number, r, fp, bp);			
		}
		else if (ysf== 2)
		{
			a5 = jisuan2(sig[0], sig[1], a1, a2, a3, a5, a6);
			if (a5.fenzi < 0)
				continue;
				while (a<number)
				{
					if(chachong[a][0]==a5.fenzi&&chachong[a][1]==a5.fenmu)
					{
						a++;
						flag=1;
						break;
					}
					chachong[a][0]=a5.fenzi;
					chachong[a][1]=a5.fenmu;
					a++;
					flag=0;	
				}
				if(flag==1)
				continue;
			shuchu(sig[0], sig[1], sig[2], a1, a2, a3, a4, a5, number, r, fp, bp);
		}
		else

		{
			a5 = jisuan3(sig[0], sig[1], sig[2], a1, a2, a3, a4, a5);
			if (a5.fenzi < 0)
				continue;
				while (a<number)
				{
					if(chachong[a][0]==a5.fenzi&&chachong[a][1]==a5.fenmu)
					{
						a++;
						flag=1;
						break;
					}
					chachong[a][0]=a5.fenzi;
					chachong[a][1]=a5.fenmu;
					a++;
					flag=0;	
				}
				if(flag==1)
				continue;				
			shuchu(sig[0], sig[1], sig[2], a1, a2, a3, a4, a5, number, r, fp, bp);
		}

		i++;
		number++;
	}
	fclose(fp);
	fclose(bp);
	printf("生成成功\n"); 
	return 0;

}

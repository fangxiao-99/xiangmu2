#include<stdio.h>
#include<string.h> 



int main()
{
	int tishu = 0;      //�ļ������� 
	int c;
	char str1[10000];   //��Ŀ�ļ��Ĵ� 
	char str2[10000];   //���ļ��Ĵ� 
	int t, f = 0;   //�Դ������ 
	int x, y = 0; 
	int correct[10000]; //��ȷ����� 
	int wrong[10000];   //�������� 
	int p = 0;
	FILE *fp, *bp, *cp;
	fp = fopen("exercisefile.txt", "r");
	bp = fopen("answerfile.txt", "r");
	cp = fopen("Grade.txt", "w");
	if(fp == NULL || bp == NULL || cp == NULL)
	{
		printf("error");
	}
	else
	{
		c = fgetc(fp);
		while(c != EOF)   //��ȡ���� 
		{
			if(c == '\n')
			{
				tishu++;
			}
			c = fgetc(fp);
		}
		fseek(fp, 0L, 0); //�ļ�ָ��ص���ͷ 
		
		for(int i = 1; i <= tishu; i++)
		{
		    fscanf(fp, "%*[^=]=%s", str1); 
		    fscanf(bp, "%*[^=]=%s", str2); 
		    
            p = strcmp(str1,str2);
            if(p == 0)
			   {
				    correct[x] = i;
				    x++;
				    t++;
			   }
			   else
			   {
			   	    wrong[y] = i;
			   	    y++;
			   	    f++;
			   }  
		}
	    fclose(fp);
	    fclose(bp);
	}
	    
		fprintf(cp, "Correct��%d (", t);
	    for(int i = 0; i < t; i++)
	    {
	    	fprintf(cp, "%d", correct[i]);
	    	if(i != t-1)
	    	{
	    		fprintf(cp, ",");
			}
		}
		fprintf(cp, ")\n");
		
		fprintf(cp, "Wrong��%d (", f);
	    for(int i = 0; i < f; i++)
	    {
	    	fprintf(cp, "%d", wrong[i]);
	    	if(i != f-1)
	    	{
	    		fprintf(cp, ",");
			}
		}
		fprintf(cp, ")\n");

	printf("�жϳɹ�"); 
 }

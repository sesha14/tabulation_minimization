#include<stdio.h>
#include<stdlib.h>
main()
{
	int i,j,l,n=0,s,f,flag,k,z=0,m=0,p,n1=0,pp,cp,cp1,l1,l2,q;
	FILE *fp;
        FILE*fp1;
	char ch;
	printf("enter no.of states:\n");
	scanf("%d",&n);
	char a[n],u[n];
	char fi[n][n];
	char fo[n][n];
	char fz[n][n];
	int c[n],zero[n],one[n],col[n],b[n],d[n];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			fi[i][j]='\0';
			fo[i][j]='\0';
			fz[i][j]='\0';
		}
	}
	printf("enter the states in order:\n");
	for(i=0;i<n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch;
	}
	printf("\n");
	for(i=0;i<(n-1);i++)
	{
		c[i]=1;
	}
	c[i]=n;
	printf("enter the transitions on o:\n");
	for(i=0;i<n;i++)
	{
		scanf(" %c",&ch);
		for(j=0;j<n;j++)
		{
			if(ch==a[j])
			zero[i]=j;
		}
	}
	printf("\n");
	printf("enter the transitions on 1:\n");
	for(i=0;i<n;i++)
	{
		scanf(" %c",&ch);
		for(j=0;j<n;j++)
		{
			if(ch==a[j])
			one[i]=j;
		}
	}
	printf("\n");
	flag=2;
	while(z!=1)
	{
		for(i=0;i<n;i++)
		col[i]=c[i];
		z=0;
		for(i=1;i<(n-1);i++)
		{
			k=0;
			for(j=0;j<i;j++)
			{
				if(c[zero[i]]==c[zero[j]] && c[one[i]]==c[one[j]])
				{
					c[i]=c[j];
					k++;
					break;
				}
			}
			if((k==0) && (flag!=n))
			{
				c[i]=flag;
				flag++;
			}
		}
		m=0;
		for(i=0;i<n;i++)
		{
			if(col[i]!=c[i])
			{
				m++;
				break;
			}
		}
		if(m==0)
		z=1;
		}
	printf("\nMinimal sets after minimization of dfa are:\n");m=1;
	for(i=1;i<flag;i++)
	{
		f=0;n1=0;
		for(j=0;j<n;j++)
		{
			if(c[j]==i)
			{
			printf("%c",a[j]);
			fi[m][n1]=a[j];
			n1++;f++;
			}
		}
		if(f!=0)
		printf("\n");	
        m++;	
	}
	printf("%c",a[n-1]);
	fi[n][0]=a[n-1];
	printf("\nfinal zero transition:\n");m=0;
	for(i=0;i<=flag;i++)
	{
        n1=0;ch='\0';q=0;
		for(j=0;j<n;j++)
		{
			if(col[j]==i&&ch!=a[zero[j]]&&q==0)
			{	
			  for(l1=0;l1<=n;l1++)
			  {
			  	for(l2=0;fi[l1][l2]!='\0';l2++)
			  	{
			  		if(a[zero[j]]==fi[l1][l2]&&l2!=0)
			  		{
			  			s=0;q=1;
			  			while(fi[l1][s]!='\0')
			  			{
			  				fz[m][n1]=fi[l1][s];
			  				printf("%c",fi[l1][s]);
			  				s++;n1++;
			  			}
			  		}
			  		if(a[zero[j]]==fi[l1][l2]&&l2==0)
			  		{
			  			s=0;q=1;
			  			while(fi[l1][s]!='\0')
			  			{
			  				fz[m][n1]=fi[l1][s];
			  				printf("%c",fi[l1][s]);
			  				s++;n1++;
			  			}
			  		}
			  	}
			  }
              ch=a[zero[j]];
		    }
		}
		printf("  ");m++;
	}
		printf("\nfinal one transition:\n");
		m=0;
	for(i=0;i<=flag;i++)
	{
		ch='\0';n1=0;q=0;
		for(j=0;j<n;j++)
		{
			
			if(col[j]==i&&ch!=a[one[j]]&&q==0)
			{
			 for(l1=0;l1<=n;l1++)
			  {
			  	for(l2=0;fi[l1][l2]!='\0';l2++)
			  	{
			  		if(a[one[j]]==fi[l1][l2]&&l2!=0)
			  		{
			  			s=0;q=1;
			  			while(fi[l1][s]!='\0')
			  			{
			  				fo[m][n1]=fi[l1][s];
			  				printf("%c",fi[l1][s]);
			  				s++;n1++;
			  			}
			  		}
			  		if(a[one[j]]==fi[l1][l2]&&l2==0)
			  		{
			  			s=0;q=1;
			  			while(fi[l1][s]!='\0')
			  			{
			  				fo[m][n1]=fi[l1][s];
			  				printf("%c",fi[l1][s]);
			  				s++;n1++;
			  			}
			  		}
			  	}
			  }	
			 ch=a[one[j]];
		    }
		}
		printf("  ");m++;
	}
	fp=fopen("E:\\file.txt","w+");
	fputs("digraph finite_state_machine {rankdir=LR;",fp);
	ch='"';
	for(i=0;i<n;i++)
	{
		fputc(a[i],fp);
		fputs("->",fp);
		fputc(a[zero[i]],fp);
		fputs(" [ label =",fp);
		fputc(ch,fp);
		fputs("a",fp);
		fputc(ch,fp);
		fputs("];",fp);
	}
	for(i=0;i<n;i++)
	{
		fputc(a[i],fp);
		fputs("->",fp);
		fputc(a[one[i]],fp);
		fputs(" [ label =",fp);
		fputc(ch,fp);
		fputs("b",fp);
		fputc(ch,fp);
		fputs("];",fp);
	}
	fputs("}",fp);
	printf("\n");
	fp1=fopen("E:\\file1.txt","w+");
	fputs("digraph finite_state_machine {rankdir=LR;",fp1);
        ch='"';
        
        for(i=1;i<=n;i++)
        {
        	pp=0;
         for(j=0;fi[i][j]!='\0';j++)
         {
         fputc(fi[i][j],fp1);pp++;
         }
         if(pp!=0)fputs("->",fp1);
         for(j=0;fz[i][j]!='\0';j++)
         fputc(fz[i][j],fp1);
         if(pp!=0)
         {
         fputs(" [ label =",fp1);
	     fputc(ch,fp1);
	     fputs("a",fp1);
	     fputc(ch,fp1);
	     fputs("];",fp1);
        }
        }
        
        for(i=1;i<=n;i++)
        {
        	pp=0;
         for(j=0;fi[i][j]!='\0';j++)
         {
         fputc(fi[i][j],fp1);pp++;
         }
         if(pp!=0)
		 fputs("->",fp1);
         for(j=0;fo[i][j]!='\0';j++)
         fputc(fo[i][j],fp1);
         if(pp!=0)
         {
         fputs(" [ label =",fp1);
	     fputc(ch,fp1);
	     fputs("b",fp1);
	     fputc(ch,fp1);
	     fputs("];",fp1);}
        }
        fputs("}",fp1);
	 fclose(fp);
	 fclose(fp1);
}

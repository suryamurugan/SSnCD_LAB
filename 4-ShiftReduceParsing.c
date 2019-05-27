#include<stdio.h>
//#include<conio.h>
#include<string.h>
//#include<process.h>

char stk[20],input[20],act[20];

void main()
{
	int i=0,k=0,c;
	strcpy(stk,"$");
	printf("The grammer is E->E+T|T\nT->T*F|F\nF->(E)|id\n");
	printf("input the string\n");
	scanf("%s",input);
	c=strlen(input);
	printf("stack\tInput\tAction\n");
	while(i<=c)
	{
		if(stk[k]=='$')
		{
			if(input[i]=='(')
			{
				stk[k]='(';
				input[i]=' ';
				i=i+1;
			}
			else if(input[i]=='i'&&input[i+1]=='d')
			{
				stk[k]='i';
				stk[k+1]='d';
				k=k+1;
				input[i]=' ';
				input[i+1]=' ';
				i=i+2;
			}
			else
			{
				printf("error input\n");
				exit(0);
			}
			strcpy(act,"Shift");
			printf("$%s\t%s$\t%s\n",stk,input,act);
		}
		else if(stk[k]=='(')
		{
			if(input[i]=='i'&&input[i+1]=='d')
			{
				stk[k+1]=input[i];
				stk[k+2]=input[i+1];
				k=k+1;
				input[i]=' ';
				input[i+1]=' ';
				i=i+2;
			}
			else
			{
				printf("error input");
				exit(0);
			}
			strcpy(act,"Shift");
			printf("$%s\t%s$\t%s\n",stk,input,act);
		}
		else if(stk[k-1]=='i'&&stk[k]=='d')
		{
			if(input[i]=='+'|| input[i]=='*'||input[i]=='\0')
			{
				stk[k-1]='F';
				stk[k]=' ';
				k=k-1;
				strcpy(act,"Redue F->id");
			}
			else
			{
				printf("error input\n");
				exit(0);
			}
			printf("$%s\t%s$\t%s\n",stk,input,act);
		}
		else if(stk[k]=='*'||stk[k]=='+')
		{
			if(input[i]=='i'&&input[i+1]=='d')
			{
				stk[k+1]='i';
				stk[k+2]='d';
				k=k+2;
				input[i]=' ';
				input[i+1]=' ';
				i=i+2;
				strcpy(act,"Shift");
			}
			else
			{
				printf("error input");
				exit(0);
			}
			printf("$%s\t%s$\t%s\n",stk,input,act);
		}
		else if(stk[k]=='F')
		{
			if(input[i]=='+'||input[i]=='*'||(input[i]=='\0'&&stk[k-1]=='+'))
			{
				stk[k]='T';
				strcpy(act,"RedceT->F");
			}
			else if(input[i]=='\0'&&stk[k-1]=='*')
			{
				stk[k-2]='T';
				stk[k]=' ';
				stk[k-1]=' ';
				k=k-2;
				strcpy(act,"ReduceT->T*F");
			}
			else
			{
				printf("error input");
				exit(0);
			}
			printf("$%s\t%s$\t%s\n",stk,input,act);
		}
		else if(stk[k]=='T')
		{
			if(input[i]=='+')
			{
				stk[k]='E';
				strcpy(act,"Reduce E->T");
			}
			else if(input[i]=='*')
			{
				stk[k+1]='*';
				k=k+1;
				input[i]=' ';
				i=i+1;
				strcpy(act,"Shift");
			}
			else if(input[i]=='\0')
			{
				stk[k-2]='E';

			       stk[k]=' ';
				stk[k-1]=' ';
				k=k-2;
				strcpy(act,"Reduce E->E+T");
			}
			else
			{
				printf("error input");
				exit(0);
			}
			printf("$%s\t%s$\t%s\n",stk,input,act);
		}
		else if(stk[k]=='E')
		{
			if(input[i]=='+'||input[i]==')')
			{
				stk[k+1]=input[i];
				k=k+1;
				input[i]=' ';
				i=i+1;
				strcpy(act,"Shift");
			}
			else if(input[i]=='\0')
			{
				strcpy(act,"Accept");
				printf("$%s\t%s$\t%s\n",stk,input,act);
				exit(0);
			}
			printf("$%s\t%s$\t%s\n",stk,input,act);

			}
		else if(stk[k]==')')
		{
			stk[k-2]='F';
			stk[k]=' ';
			stk[k-1]=' ';
			k=k-2;
			strcpy(act,"Redue F->(E)");
			printf("$%s\t%s$\t%s\n",stk,input,act);
		}
		else
		{
			printf("error input");
			exit(0);
		}
	}
	//getch();
}









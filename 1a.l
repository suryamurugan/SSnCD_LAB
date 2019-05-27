%{
	#include<stdio.h>
	int id=0,op=0,bc=0,i=0,j=0,x;
	int flag=0;
	char opa[20];
	char ida[20];
%}
%%
"(" {bc++; flag=1;}
")" {if(flag==1) { bc--; flag=0;}
else bc--;
}
"+"|"*" { op++; opa[i++]=*yytext;}
[0-9]+ { id++; ida[j++]=atoi(yytext);}
. ;
%%
yywrap()
{
	return 1;
}
main()
{
printf("Enter the expression:");
yylex();
if((flag!=0)||(bc!=0)||(id-op)!=1)
{
	printf("Invalid Expression!!\n");
}
else
{
	printf("Valid expression\n");
printf("List of operators are:\n");
for(x=0;x<i;x++)
	printf("%c\t",opa[x]);
printf("\nNo of operators are:%d\n",i);
printf("List of identifiers are:");
for(x=0;x<j;x++)
	printf("%d",ida[x]);
printf("\nNo of identifiers are:%d\n",j);
}
}

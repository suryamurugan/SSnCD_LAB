%{
	int yywrap();
	void yyerror();
	int yyparse();
%}
%{
	#include<stdio.h>
	int valid=1,c=0,n;
	extern FILE *yyin;
%}
%token A
%token B
%%
	S:A S {c++;}|B;
%%
void yyerror()
{
	valid=0;
}
int yywrap()
{
	return 1;
}
int main()
{
	printf("enter the value for n:\n");
	scanf("%d",&n);
	yyin=fopen("string.txt","r");
	yyparse();
	if(valid==0 || c!=n)
	{
		printf("invalid string\n");
	}
	if(valid==1 && c==n)
	{
		printf("valid string\n");
	}
	fclose(yyin);
}


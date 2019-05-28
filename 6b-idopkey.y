%{ int yywrap();
void yyerror();
int yyparse();
%}
%{
#include<stdio.h>
int id=0,key=0,op=0,valid=1;
extern FILE *yyin;
%}
%token ID KEY OP
%%
input:ID {id++;}|KEY {key++;}|OP {op++;}|input ID {id++;}|input OP {op++;}|input KEY {key++;}
%%
void yyerror()
{
	valid=0;
}
int yywrap()
{
	return 1;}
int main()
{
	yyin=fopen("input.c","r");
	yyparse();
	if(valid!=0)
	printf("%d %d %d",id,op,key);
}
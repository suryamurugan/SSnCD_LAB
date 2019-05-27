%{ int yywrap();
void yyerror();
int yyparse();
%}
%{ #include <stdio.h>
int valid=1,flag=1;
%}
%token num;
%left '+''-'
%left '*''/'
%left '('')'
%nonassoc UMINUS
%%
expr:e {if((flag==1)&&(valid==1))
			printf("result %d\n",$$);
		if((flag==1)&&(valid==0))
			printf("division by by zero not allowed \n");
		}
e:e'+'e {$$=$1+$3;}
|e'-'e {$$=$1-$3;}
|e'*'e {$$=$1*$3;}
|e'/'e {if($3==0) valid=0;
				else $$=$1/$3;}
|'-'e %prec UMINUS {($$=-$2);}
|'('e')' {$$=$2;}
|num {$$=$1;}
%%
void yyerror()
{
flag=0;}
int yywrap()
{
return 1;}
int main()
{
printf("enter the expr:\n");
yyparse();
if(flag==0)
printf("expr is wrong\n");
}


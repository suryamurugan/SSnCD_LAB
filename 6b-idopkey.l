%{
	#include<stdio.h>
	#include "y.tab.h"
	extern int yylval;
%}
%%
[\t] ;
[+|-|*|\|=] {printf("operator is %c\n",yytext[0]);
				return OP;}
int|main|printf|for {printf("\n keyword is %s\n",yytext);
							return KEY;}
[_a-zA-Z][0-9A-Z]* {printf("\n identifier is %s\n",yytext);
								return ID;}
[0-9][a-z][0-9a-z]* ;
"(".*");" ;
 . ;
%%

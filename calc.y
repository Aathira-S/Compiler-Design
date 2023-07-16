%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void); // Declaration for yylex function
void yyerror(const char *s); // Declaration for yyerror function
int flag = 0;
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%left '(' ')'
%%
ArithmeticExpression: E {
printf("\nResult = %d\n", $$);
return 0;
};
E : E '+' E { $$ = $1 + $3; }
| E '-' E { $$ = $1 - $3; }
| E '*' E { $$ = $1 * $3; }
| E '/' E { $$ = $1 / $3; }
| '(' E ')' { $$ = $2; }
| NUMBER { $$ = $1; }
;
%%
int main()
{
printf("\nEnter any arithmetic expression:\n");
yyparse();
if (flag == 0)
printf("\nEntered arithmetic expression is Valid\n\n");
return 0;
}
void yyerror(const char *s)
{
printf("\n%s\n\n", s);
flag = 1;
}

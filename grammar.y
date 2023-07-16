/* Definition section */
%{
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
int yylex(void);
void yyerror(char*);
extern char *yytext;
%}
%token ID EQ ML NL
/* Rule Section */
%%
stmt: S NL { printf("valid string\n");
 exit(0); }
S: A EQ B | B
;
A: ML B | ID
;
B: A
;
%%
void yyerror(char *s)
{
 printf("invalid string\n");
 exit(0);
}
//driver code
int main()
{
 printf("enter the string\n");
 yyparse();
}

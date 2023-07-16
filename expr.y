%{
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
//int yylex();
void yyerror(char *s);
void L1();
void Lcond();
void End();
void push();
void codegen();
void codegen_assign();
extern char *yytext;
%}
%token ID NUM WHILE
%right '='
%left '+' '-'
%right '*' '/'
%%
S: E {End();}
E: V '=' {push();} E {codegen_assign();}
| E '+' {push();} E {codegen();}
| E '-' {push();} E {codegen();}
| E '*' {push();} E {codegen();}
| E '/' {push();} E {codegen();}
| '('E')'
| V
| NUM {push();}
;
V: ID {push();}
;
%%
char st[100][10];
int top=0;
char temp[3] = "t0";
int main()
{
 printf("Enter expression\n");
 yyparse();
}
void push()
{
 strcpy(st[top],yytext);
 top++;
}
void codegen()
{
 printf("%s = %s %s %s\n", temp, st[top-3], st[top-2], 
st[top-1]);
 top = top - 3;
 strcpy(st[top],temp);
 temp[1]++;
 top++;
}
void codegen_assign()
{
 printf("%s = %s\n", st[top-3], st[top-1]);
 top = top - 3;
}
void L1()
{
 printf("\nL1: \n");
}
void Lcond()
{
 printf("%s=not %s\n", temp, st[top]);
 printf("if %s goto END\n", temp);
 temp[1]++;
}
void End()
{
 printf("\n");
}
void yyerror(char* s)
{
 printf("Invalid statement\n");
 exit(0);
}

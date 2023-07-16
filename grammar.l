/*
Grammar:
S → A=B | B
A → *B | id
B → A
*/


%{
#include "y.tab.h"
%}
%%
id return ID;
= return EQ;
'*' return ML;
\n return NL;
[ \t] ;
. return yytext[0];
%%
int yywrap()
{
 return 1;
}

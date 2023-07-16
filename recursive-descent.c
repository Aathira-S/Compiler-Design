/*
Grammar:
S → + S S | * S S | a
*/

#include <stdio.h>
#include <string.h>
#define SUCCESS 1
#define FAILED 0

int S();
const char *cursor;
char string[64];
int main()
{
puts("Enter the string");
scanf("%s", string);
cursor = string;
puts("");
puts("Input Action");
puts("--------------------------------");
if (S() && *cursor == '\0') {
puts("--------------------------------");
puts("String is successfully parsed");
return 0;
} else {
puts("--------------------------------");
puts("Error in parsing String !!");
printf("Error reported at character '%c'", 
(cursor[0]!='\0')?cursor[0]:'$');
return 1;
}
}
int S()
{
  if (*cursor == '+') {
    printf("%-16s S -> + S S\n", cursor);
    cursor++;
    if (S()) {
      if (S())
      return SUCCESS;
      else
      return FAILED;
    } else
    return FAILED;
  } else if (*cursor == '*') {
    printf("%-16s S -> * S S\n", cursor);
    cursor++;
    if (S()) {
      if (S())
      return SUCCESS;
      else
      return FAILED;
    } else
      return FAILED;
  } else if (*cursor == 'a') {
    printf("%-16s S -> a\n", cursor);
    cursor++;
    return SUCCESS;
  } else {
  return FAILED;
  }
}

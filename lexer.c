#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_TOK_LEN 100 // arbitrary max number of tokens
// enumerate the tokens as defined in question
typedef enum {
IF,
ELSE,
COMPARISON,
ID,
NUMBER,
LITERAL,
BLOCK,
OTHER
} TokenType;
// create a structure to store token along with lexeme
typedef struct {
TokenType type;
char value[MAX_TOK_LEN];
} Token;
// find the token type for lexeme found, returns token type
TokenType getTokenType(char* token) {
if (strcmp(token, "if") == 0) {
return IF;
} else if (strcmp(token, "else") == 0) {
return ELSE;
} else if (
strcmp(token, "<") == 0 ||
strcmp(token, ">") == 0 ||
strcmp(token, "<=") == 0 ||
strcmp(token, ">=") == 0 ||
strcmp(token, "==") == 0 ||
strcmp(token, "!=") == 0
) {
return COMPARISON;
} else if (isalpha(token[0])) {
return ID;
} else if (isdigit(token[0])) {
return NUMBER;
} else if (token[0] == '"' && token[strlen(token) - 1] == '"') {
return LITERAL;
} else if (strcmp(token, "(") == 0 || strcmp(token, ")") == 0 ||
strcmp(token, "{") == 0 || strcmp(token, "}") == 0) {
return BLOCK;
} else {
return OTHER;
}
}
// print the token along with lexeme (as needed)
void displayToken(Token token) {
printf("Token: ");
switch (token.type) {
case IF:
printf("if");
break;
case ELSE:
printf("else");
break;
case COMPARISON:
printf("comparison");
break;
case ID:
printf("id");
break;
case NUMBER:
printf("number");
break;
case LITERAL:
printf("literal");
break;
case BLOCK:
printf("block");
break;
case OTHER:
printf("other");
break;
}
if (token.type == ID || token.type == NUMBER) {
printf(", Value: %s", token.value);
}
printf("\n");
}
// identify the tokens in the file
void tokenize(FILE* file) {
char token[MAX_TOK_LEN];
// read file till we reach its end
while (fscanf(file, "%s", token) != EOF) {
Token currentTok;
currentTok.type = getTokenType(token); //identify which token
strcpy(currentTok.value, token); //save identified token in the current 
token variable
displayToken(currentTok); // print token
}
}
int main() {
char filename[100];
printf("Enter the file name: ");
scanf("%s", filename);
FILE* fileobj = fopen(filename, "r");
if (fileobj == NULL) {
printf("Error opening file\n");
return 1;
}
tokenize(fileobj);
fclose(fileobj);
return 0;
}

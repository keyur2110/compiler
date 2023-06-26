%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#define STR_SIZE 80
#define MAX_ID_LIST 16

extern int line_num;


void yyerror(char *s);
void check_id(char *str);
int yywrap();
int yylex();
void type_checking(char *name);


//FILE *yyin;
char id[MAX_ID_LIST][STR_SIZE];
enum TYPE typeVar;
int varIndex=0;

%}
// STR_SIZE is defined in Scanner.l before "y.tab.h"
%union {
   int ival;
   float fval;
   char name[STR_SIZE];
   char type[STR_SIZE]; 
}

%start Start

%token _PROGRAM _BEGIN _END _VAR _INTEGER _REAL
_COLON _SEMI _ASSIGN _COMMA _LPAREN _RPAREN _ADD _SUB _MULT _DIV _CONST_I _CONST_F _ID


%%
Start : _PROGRAM  _ID  _SEMI Block ;
Block :  _VAR block1 block2 B;
block1 : _ID stm _COLON A _SEMI  {
                                                            if (-1 == hash_search($<name>1)) {
                                                               hash_insert($<name>1, $<type>4);
                                                               int i=0;
                                                               for (i=0; i<varIndex; i++)
                                                                    hash_insert(id[i], $<type>4);
                                                               varIndex = 0;
                                                            }
                                                            else {
                                                                printf("Identifier redefined: %s ... (Line %d)\n", $<name>1, line_num);
                                                                exit(0);
                                                           } };

block2:block1 block2|;                             
stm : _COMMA _ID stm  {
                                            if (-1 == hash_search($<name>2)) {
                                               strcpy(id[varIndex++], $<name>2);
                                            }
                                            else {
                                                printf("Identifier redefined: %s ... (Line %d)\n", $<name>2, line_num);
                                                exit(0);
                                            }
                                        }
  | ;

A : _INTEGER|_REAL;
B : _BEGIN B1 _END;
B1 :_ID _ASSIGN exp _SEMI B1|; 
exp : Term exp1;
exp1 : _ADD Term exp1| _SUB Term exp1 |;
Term : factor Term1;
Term1 : _MULT factor Term1|_DIV factor Term1|;
factor : _ID|_CONST_I |_CONST_F |_LPAREN exp _RPAREN ;

%%
void yyerror(char *s)
{
    printf("%s at line %d\n",s,line_num);
    exit(0);
}




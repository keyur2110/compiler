// gcc main.c y.tab.c lex.yy.c 
// ./a.out test1.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void yyerror(); 
extern int  yylex();
extern FILE *yyin;
extern int yyparse();


int main(int argc, char **argv)
{
    if ( argc > 1 ) {
        if ((yyin = fopen( argv[1], "r" )) == NULL) {
            printf("%s cannot be opened\n", argv[1]);
            exit(0);
        }
    }
    else
        yyin = stdin;

    if (yyparse() == 0) {
    	printf("\nProgram has been parsed successfully\n\n");
    }
    
    return 0;
}
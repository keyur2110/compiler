#ifndef _BINARYTREE_H
#define _BINARYTREE_H

enum TYPE {UNDEFINED, INTEGER, FLOAT, OPERATOR, ID};

typedef struct {
        union{
        int ival;
        float fval;
        char *op;
        };
    enum TYPE kind;
} ITEM;

typedef struct Abstract_syntax_tree {
  	ITEM *item;
  	struct Abstract_syntax_tree *left;
  	struct Abstract_syntax_tree *right;
} NODE;




#endif
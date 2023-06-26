#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree.h"


NODE* create_node(ITEM item, NODE *left, NODE *right)
{
        NODE *result=malloc(sizeof(NODE));
        result->item = malloc(sizeof(result->item)); 
        result->left=left;
        result->right=right;
 
       if(item.kind==OPERATOR)
       {
           result->item->op=item.op;
           result->item->kind=OPERATOR;
        }
       else if(item.kind==ID)
       {
           result->item->op=item.op;
           result->item->kind=ID;
       }
      else if(item.kind==INTEGER)
       {
           result->item->ival=item.ival;
           result->item->kind=INTEGER;
       }
      else if(item.kind==FLOAT)
       {
           result->item->fval=item.fval;
           result->item->kind=FLOAT;
       }
        
        
    return result;
}



void print_tree(NODE *tree)
{

    if(tree == NULL)
    {   
        return;
    }
    if(tree->left!=NULL && tree->right!=NULL)
    {
        printf(" (");
    }

        
    if(tree->item->kind==OPERATOR)
    {
        printf("%s",tree->item->op);

    }
   if(tree->item->kind==ID)
       {
          printf(" %s", tree->item->op);
       }
    if(tree->item->kind==INTEGER)
       {
           printf(" %2d", tree->item->ival);
       }
    if(tree->item->kind==FLOAT)
       {
          printf(" %.1f", tree->item->fval);
       }
       
    if(tree->left==NULL && tree->right==NULL)
    {
        return;
    }
    
    
    print_tree(tree->left);

    
    if(tree->right!=NULL)
    {       
        print_tree(tree->right);
        printf(")");
    }
    

    
    
    
}
void free_node(NODE *tree)
{
    if(tree != NULL)
    {
    free_node(tree->left);
    free_node(tree->right);
    free(tree->item); 
    free(tree);
    
    }
}


// num1 := 2 * 3.2 + 10
// print_tree -> (:= num1 (+ (* 2 3.2) 10)) 
int main()
{
    ITEM item;
    
    item.op = "num1";
    item.kind = ID;
    NODE *node1 = create_node(item, NULL, NULL);

    item.ival = 10;
    item.kind = INTEGER;
    NODE *node2 = create_node(item, NULL, NULL);
   
    item.ival = 2;
    item.kind = INTEGER;
    NODE *node3 = create_node(item, NULL, NULL);

    item.fval = 3.2;
    item.kind = FLOAT;
    NODE *node4 = create_node(item, NULL, NULL);


    item.op = "*";
    item.kind = OPERATOR;
    NODE *node5 = create_node(item, node3, node4);
 
    item.op = "+";
    item.kind = OPERATOR;
    NODE *node6 = create_node(item, node5, node2);

    item.op = ":=";
    item.kind = OPERATOR;
    NODE *tree = create_node(item, node1, node6);

    // preorder  
    print_tree(tree);
    printf("\n");

    // postorder
    free_node(tree);
    
    return 0;
}